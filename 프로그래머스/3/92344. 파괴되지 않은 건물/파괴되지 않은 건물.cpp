#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    vector<vector<int>> skill_board(board.size() + 1, vector<int>(board[0].size() + 1 , 0));
    
    for (auto s : skill)
    {
        int type = s[0];
        int r1 = s[1];
        int c1 = s[2];
        int r2 = s[3];
        int c2 = s[4];
        int degree = s[5];
        
        skill_board[r1][c1] += (type == 1) ? -1 * degree : degree;
        skill_board[r2 + 1][c1] -= (type == 1) ? -1 * degree : degree;
        
        skill_board[r1][c2 + 1] -= (type == 1) ? -1 * degree : degree;
        skill_board[r2 + 1][c2 + 1] += (type == 1) ? -1 * degree : degree;   
    }
    
    
    
    for (int r = 0; r < board.size(); r++)
    {
        int score = 0;
        for (int c = 0; c < board[r].size(); c++)
        {
            score += skill_board[r][c];
            skill_board[r][c] = score;
        }
    }
    
    for (int c = 0; c < board[0].size(); c++)
    {
        int score = 0;
        for (int r = 0; r < board.size(); r++)
        {
            score += skill_board[r][c];
            board[r][c] += score;
            if (board[r][c] > 0) answer++;
        }
    }
    
    
    return answer;
}