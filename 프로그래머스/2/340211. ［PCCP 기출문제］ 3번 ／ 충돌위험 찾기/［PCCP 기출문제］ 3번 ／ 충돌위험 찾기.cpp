#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> GetNextRC(vector<int> current, vector<int> route, vector<vector<int>> points, int& idx)
{
    if (current[0] == -999) return current;
    
    if (current == points[route[idx] - 1])
    {
        if ((idx + 1) >= route.size())
        {
            return { -999, -999 };
        }
        else
        {
            idx++;
        }
    }
    
    vector<int> next = points[route[idx] - 1];
    if (next[0] - current[0] != 0)
    {
        current[0] = current[0] + (next[0] - current[0]) / abs(next[0] - current[0]);
        return current;
    }
    
    if (next[1] - current[1] != 0)
    {
        current[1] = current[1] + (next[1] - current[1]) / abs(next[1] - current[1]);
        return current;
    }
}

bool IsAllArrive(vector<vector<int>> currents, vector<vector<int>> routes, vector<vector<int>> points)
{
    for (int i = 0; i < currents.size(); i++)
    {
        if (currents[i][0] != -999)
        {
            return false;
        }
    }
    return true;
}


int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    
    vector<vector<int>> currents;
    vector<int> next_points_idx;
    
    for (auto route : routes)
    {
        currents.push_back(points[route[0]-1]);
        next_points_idx.push_back(1);
    }
    
    while(!IsAllArrive(currents, routes, points))
    {
        int arr[101][101] = {};
        
        for (auto current : currents)
        {
            if (current[0] == -999) continue;
            arr[current[0]][current[1]]++;
        }
        
        for (int r = 1; r < 101; r++)
        {
            for (int c = 1; c < 101; c++)
            {
                if (arr[r][c] > 1) answer++;
            }
        }
        
        for (int i = 0; i < currents.size(); i++)
        {
            currents[i] = GetNextRC(currents[i], routes[i], points, next_points_idx[i]);
        }
    }
    
    
   
    
    
    
    return answer;
}