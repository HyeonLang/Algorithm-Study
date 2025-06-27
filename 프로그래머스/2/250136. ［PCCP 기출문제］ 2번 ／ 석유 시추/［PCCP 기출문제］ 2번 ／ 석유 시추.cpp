#include <string>
#include <vector>
#include <deque>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

vector<int> calcOil(vector<vector<int>> land)
{
    vector<int> result(land[0].size() + 1, 0);
    for (int i = 0; i < land.size(); i++)
    {
        for (int j = 0; j < land[i].size(); j++)
        {
            if (land[i][j] == 0) continue;
            int count = 0;
            int max_j = j;
            int min_j = j;
            deque<vector<int>> q;
            q.push_back({i, j});
            land[i][j] = 0;
            while(!q.empty())
            {
                vector<int> top = q.front();
                q.pop_front();
                max_j = max(max_j, top[1]);
                min_j = min(min_j, top[1]);
                count++;
            
                for (auto d : dir)
                {
                    int next_i = top[0] + d[0];
                    int next_j = top[1] + d[1];
                    if (next_i < 0 || next_i >= land.size()) continue;
                    if (next_j < 0 || next_j >= land[next_i].size()) continue;
                    if (land[next_i][next_j] == 0) continue;
                
                    land[next_i][next_j] = 0;
                    q.push_back({next_i, next_j});
                }
            }
            
            result[min_j] += count;
            result[max_j + 1] -= count;
        }
    }
    return result;
}

bool compare(vector<int> a, vector<int> b)
{
    if (a[1] < b[1]) return true;
    return false;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    
    vector<int> oil_list = calcOil(land);
    priority_queue<int> oil_count;
    
    int count = 0;
    for (int i = 0; i < oil_list.size(); i++)
    {
        count += oil_list[i];
        oil_count.push(count);
    }
    
    return oil_count.top();
}