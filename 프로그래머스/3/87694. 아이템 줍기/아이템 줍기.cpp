#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int INF = 99999999;
int dir[4][2] = {{1, 0}, {-1, 0}, {0,1}, {0,-1}};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    vector<vector<int>> board(101, vector<int>(101, 0));
    
   
    for (auto rec : rectangle)
    {
        for (int x = rec[0] * 2; x <= rec[2] * 2; x++)
        {
            for (int y = rec[1] * 2; y <= rec[3] * 2; y++)
            {
                if (x == rec[0] * 2 || y == rec[1] * 2 || x == rec[2] * 2 || y == rec[3] * 2) 
                {
                    board[x][y]++;
                }
                else 
                {
                    board[x][y] = -INF;
                    
                }
            }
        }
    }

    
    deque<vector<int>> q;
    q.push_back({characterX * 2, characterY * 2, 0});
    board[characterX * 2][characterY * 2] = -INF;
    while(!q.empty())
    {
        vector<int> top = q.front();
        //cout << top[0] << ", " << top[1] << " : "<< top[2] << endl;
        q.pop_front();
        if (top[0] == itemX * 2 && top[1] == itemY * 2)
        {
            answer = top[2];
            break;
        }
        
        for (int i = 0; i < 4; i++)
        {
            int next_x = dir[i][0] * 2 + top[0];
            int next_y = dir[i][1] * 2 + top[1];
            
            //cout << board[next_x - dir[i][0]][next_y - dir[i][1]] << endl;
            if (next_x < 0 || next_x > 100) continue;
            if (next_y < 0 || next_y > 100) continue;
            if (board[next_x - dir[i][0]][next_y - dir[i][1]] <= 0) continue;
            if (board[next_x][next_y] <= 0) continue;
            
            q.push_back({next_x, next_y, top[2] + 1});
            board[next_x][next_y] = -INF;
            board[next_x - dir[i][0]][next_y - dir[i][1]] = -INF;
        }
    }
    
    
    return answer;
}