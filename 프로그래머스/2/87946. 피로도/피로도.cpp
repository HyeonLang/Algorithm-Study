#include <string>
#include <vector>
#include <cmath>

using namespace std;

int result = 0;

void solve(int k, int count, vector<bool>& visited, vector<vector<int>>& dengeons)
{
    result = max(result, count);
    for (int i = 0; i < dengeons.size(); i++)
    {
        if (visited[i]) continue;
        if (k < dengeons[i][0]) continue;
        
        visited[i] = true;
        solve(k - dengeons[i][1], count + 1, visited, dengeons);
        visited[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    vector<bool> visited(dungeons.size(), false);
    
    solve(k, 0, visited, dungeons);
    
    answer = result;
    return answer;
}