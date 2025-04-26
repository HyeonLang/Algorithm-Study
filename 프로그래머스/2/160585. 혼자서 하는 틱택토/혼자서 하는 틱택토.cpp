#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> board) {
    int answer = -1;
    
    int count_O = 0;
    int count_X = 0;
    
    int line_O = 0;
    int line_X = 0;
    
    for (auto line : board)
    {
        for (auto tik : line)
        {
            if (tik == 'O') count_O++;
            else if (tik == 'X') count_X++;
        }
    }
    
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            if (board[i][0] == 'X') line_X++;
            else if (board[i][0] == 'O') line_O++;
        }
        
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            if (board[0][i] == 'X') line_X++;
            else if (board[0][i] == 'O') line_O++;
        }
    }
    
    if (board[1][1] != '.')
    {
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        {
            if (board[1][1] == 'X') line_X++;
            else if (board[1][1] == 'O') line_O++;
        }
    
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        {
            if (board[1][1] == 'X') line_X++;
            else if (board[1][1] == 'O') line_O++;
        }
    }
    
    
    
    if (count_O > count_X + 1 || count_X > count_O) return 0;
    if (line_X > 1 || line_O > 2) return 0;
    if (line_O == 2 && count_O == count_X) return 0;
    if (line_O == 1 && (line_O + line_X > 1 || count_O == count_X)) return 0;
    if (line_X == 1 && (line_O + line_X > 1 || count_O == count_X + 1)) return 0;
    
    
    return 1;
}