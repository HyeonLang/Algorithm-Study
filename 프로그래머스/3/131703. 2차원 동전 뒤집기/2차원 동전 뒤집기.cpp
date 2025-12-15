#include <string>
#include <vector>

using namespace std;
int result = -1;

void solve(int i, int count, 
           vector<vector<int>>& beginning, 
           vector<vector<int>>& target)
{
    if (i == beginning[0].size())
    {
        if (result == -1) result = count;
        else result = min(result, count);
        return;
    }
    
    int is_all_opposite = -1;
    for (int r = 0; r < beginning.size(); r++)
    {
        if (beginning[r][i] == target[r][i]) 
        {
            if (is_all_opposite == 1) return;
            is_all_opposite = 0;
        }
        else
        {
            if (is_all_opposite == 0) return;
            is_all_opposite = 1;
        }
    }
    
    solve(i + 1, count + is_all_opposite, beginning, target);
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int answer = 0;
    
    vector<vector<int>> beginning_o = beginning;
    vector<vector<int>> beginning_x = beginning;
    int count_o = 0;
    int count_x = 1;
    
    for (int i = 0; i < beginning.size(); i++)
    {
        count_o += (beginning[i][0] != target[i][0]) ? 1 : 0;
        count_x += (beginning[i][0] != target[i][0]) ? 0 : 1;
        
        for (int j = 0; j < beginning[i].size(); j++)
        {
            if (beginning[i][0] != target[i][0])
                beginning_o[i][j] = (beginning_o[i][j] + 1) % 2;
            else
                beginning_x[i][j] = (beginning_x[i][j] + 1) % 2;
        }
        
    }
    
    solve(1, count_o, beginning_o, target);
    solve(1, count_x, beginning_x, target);
    
    answer = result;
    return answer;
}