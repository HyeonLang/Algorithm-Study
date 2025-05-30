#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <cmath>
#include <iostream>

using namespace std;

int result = -1;

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool IsValidIndex2D(int x, int y, const int size)
{
    if (x < 0 || x >= size) return false;
    if (y < 0 || y >= size) return false;
    return true;
}

void solve(int cost, const int& height, priority_queue<vector<int>>& pq,deque<vector<int>>& connected, vector<vector<int>>& land, vector<vector<bool>>& visited)
{
    if (connected.size() == land.size() * land.size())
    {
        result = cost;
        return;
    }
    
    vector<int> cell = connected.front();
    
    for (int d = 0; d < 4; d++)
    {
        int next_x = cell[0] + dir[d][0];
        int next_y = cell[1] + dir[d][1];
        if (!IsValidIndex2D(next_x, next_y, land.size())) continue;
        if (visited[next_x][next_y]) continue;
            
        int move_cost = abs(land[cell[0]][cell[1]] - land[next_x][next_y]);
        if (move_cost <= height) move_cost = 0;
            
        pq.push({(-1 * move_cost), next_x, next_y});
            
    }
    
    vector<int> top;
    while(true)
    {
        top = pq.top();
        pq.pop();
        if (!visited[top[1]][top[2]]) break;
    }
        
    visited[top[1]][top[2]] = true;
    connected.push_front({top[1], top[2]});
    solve(cost + (-1 * top[0]), height, pq, connected, land, visited);
}


int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    vector<vector<bool>> visited(land.size(), vector<bool>(land.size(), false));     deque<vector<int>> connected;
    priority_queue<vector<int>> pq;
    
    connected.push_front({0, 0});
    visited[0][0] = true;
    
    solve(0, height, pq, connected, land, visited);
    answer = result;
    
    return answer;
}