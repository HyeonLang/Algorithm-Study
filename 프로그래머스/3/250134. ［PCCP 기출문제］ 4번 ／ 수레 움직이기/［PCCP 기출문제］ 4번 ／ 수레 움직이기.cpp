#include <string>
#include <vector>
#include <deque>

using namespace std;

int dir[4][2] = {{1, 0}, {-1, 0}, {0 ,1}, {0, -1}};

int result = 99999;

bool IsValid(vector<int> pos, vector<vector<int>>& maze)
{
    if (pos[0] < 0 || pos[0] >= maze.size()) return false;
    if (pos[1] < 0 || pos[1] >= maze[pos[0]].size()) return false;
    return true;
}

void solve(int count, vector<int> red, vector<int> blue, vector<vector<int>>& maze, vector<vector<bool>>& red_visit, vector<vector<bool>>& blue_visit)
{
    if (count >= result) return;
    if (maze[red[0]][red[1]] == 3 && maze[blue[0]][blue[1]] == 4) 
    {
        result = count;
        return;
    }
    
    for (auto red_d : dir)
    {        
        vector<int> next_red = {red[0] + red_d[0], red[1] + red_d[1]};
        
        if (maze[red[0]][red[1]] == 3) next_red = red;
        else
        {
            if (!IsValid(next_red, maze)) continue;
            if (maze[next_red[0]][next_red[1]] == 5) continue;
            if (red_visit[next_red[0]][next_red[1]]) continue;
        }
        red_visit[next_red[0]][next_red[1]] = true;
        for (auto blue_d : dir)
        {
            vector<int> next_blue = {blue[0] + blue_d[0], blue[1] + blue_d[1]};
            if (maze[blue[0]][blue[1]] == 4) next_blue = blue;
            else
            {
                if (!IsValid(next_blue, maze)) continue;
                if (maze[next_blue[0]][next_blue[1]] == 5) continue;
                if (blue_visit[next_blue[0]][next_blue[1]]) continue;
                if (next_blue == red && next_red == blue) continue;
            }
            
            if (next_blue == next_red) continue;
            
            blue_visit[next_blue[0]][next_blue[1]] = true;
            solve(count + 1, next_red, next_blue, maze, red_visit, blue_visit);
            blue_visit[next_blue[0]][next_blue[1]] = false;
        }
        red_visit[next_red[0]][next_red[1]] = false;

    }
}


int solution(vector<vector<int>> maze) {
    int answer = 0;
    
    vector<int> red;
    vector<vector<bool>> red_visit(maze.size(), vector<bool>(maze[0].size(), false));
    vector<int> blue;
    vector<vector<bool>> blue_visit(maze.size(), vector<bool>(maze[0].size(), false));
    for (int i = 0; i < maze.size(); ++i)
    {
        for (int j = 0; j < maze[i].size(); ++j)
        {
            if (maze[i][j] == 1) 
            {
                red = {i, j};
                red_visit[i][j] = true;
            }
            if (maze[i][j] == 2) 
            {
                blue = {i, j};
                blue_visit[i][j] = true;
            }
        }
    }
    
    solve(0, red, blue, maze, red_visit, blue_visit);
    
    if (result != 99999)
        answer = result;
    return answer;
}