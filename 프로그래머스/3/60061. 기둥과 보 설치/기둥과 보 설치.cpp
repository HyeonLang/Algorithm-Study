#include <string>
#include <vector>

using namespace std;

bool CanBeam(vector<int> build, vector<vector<vector<bool>>>& map)
{
    int s_x = build[0];
    int s_y = build[1];
    int e_x = build[0];
    int e_y = build[1] + 1;
    
    if (s_y == 0) return true;
    if (map[s_x][s_y - 1][0]) return true;
    if (map[s_x][s_y][1]) return true;
    if (s_x - 1 >= 0 && map[s_x - 1][s_y][1]) return true;
    
    return false;
    
}

bool CanGirder(vector<int> build, vector<vector<vector<bool>>>& map)
{
    int s_x = build[0];
    int s_y = build[1];
    int e_x = build[0] + 1;
    int e_y = build[1];
    
    if (map[s_x][s_y - 1][0]) return true;
    if (map[e_x][e_y - 1][0]) return true;
    if (map[e_x][e_y][1] && s_x - 1 >= 0 && map[s_x - 1][s_y][1]) return true; 
    
    return false;
}

bool IsVaildMap(vector<vector<vector<bool>>>& map)
{
    for (int x = 0; x < map.size(); x++)
    {
        for (int y = 0; y < map.size(); y++)
        {
            vector<int> v = {x, y};
            if (map[x][y][0] && !CanBeam(v , map)) return false;
            if (map[x][y][1] && !CanGirder(v, map)) return false;
        }
    }
    
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    vector<vector<vector<bool>>> map(n+1, vector<vector<bool>>(n+1, vector<bool>(2, false)));
    
    for (auto build : build_frame)
    {
        int x = build[0];
        int y = build[1];
        
        if (build[3] == 1)
        {
            if (build[2] == 0)
            {
                if (CanBeam(build, map)) map[x][y][0] = true;
            }
            else
            {
                if (CanGirder(build, map)) map[x][y][1] = true;
            }
        }
        else
        {
            if (build[2] == 0)
            {
                map[x][y][0] = false;
                if (IsVaildMap(map)) continue;
                map[x][y][0] = true;
            }
            else
            {
                map[x][y][1] = false;
                if (IsVaildMap(map)) continue;
                map[x][y][1] = true;
            }
        }
    }
    
    for(int x = 0; x < map.size(); x++)
    {
        for(int y = 0; y < map[x].size(); y++)
        {
            if (map[x][y][0]) answer.push_back({x, y, 0});
            if (map[x][y][1]) answer.push_back({x, y, 1});
        }
    }
    
    return answer;
}