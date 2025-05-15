#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    vector<vector<int>> win_lose(n, vector<int>(n, 0));
    
    for (int i = 0; i < results.size(); i++)
    {
        int win = results[i][0] - 1;
        int lose = results[i][1] - 1;
        
        win_lose[win][lose] = 1;
        win_lose[lose][win] = -1;
    }
    for (int m = 0; m < n; m++)
    {
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b <= a; b++)
        {
            if (win_lose[a][m] == 1 && win_lose[m][b] == 1)
            {
                   
                win_lose[a][b] = 1;
                win_lose[b][a] = -1;
                    
            }
            if (win_lose[b][m] == 1 && win_lose[m][a] == 1)
            {
                    
                win_lose[b][a] = 1;
                win_lose[a][b] = -1;
                    
            }
            
            
        }
    }
    }
    
    answer = n;
    for (int i = 0; i < n; i++)
    {
       for (int j = 0; j < n; j++)
       {
           if (i != j && win_lose[i][j] == 0)
           {
               answer--;
               break;
           }
       }
    }
    
    return answer;
}