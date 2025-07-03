#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> rotate90(vector<vector<int>> key)
{
    int n = key.size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            result[j][n - i - 1] = key[i][j];
    }
    return result;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    
    int n = key.size();
    int m = lock.size();
    
    vector<vector<int>> wise_lock(m + 2*n, vector<int>(m + 2*n, -1));
    int wm = wise_lock.size();
    
    int blank = 0;
    for (int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            wise_lock[n + i][n + j] = lock[i][j];
            if (lock[i][j] == 0) blank++;
        }
    }
    
    
    for (int r = 0; r < 4; r++)
    {
        for (int si = 0; si < wm - n + 1; si++)
        {
            for (int sj = 0; sj < wm - n + 1; sj++)
            {
                int count = 0;
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (wise_lock[i + si][j + sj] == 1 && key[i][j] == 1) count = blank + 1;
                        if (wise_lock[i + si][j + sj] == 0 && key[i][j] == 1) count++;
                    }
                }
                if (blank == count) return true;
            }
        }
        key = rotate90(key);
    }
    
    return answer;
}