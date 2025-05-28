#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>
using namespace std;
int INF = -1;
int result = -1;

//deque<vector<int>> s;

bool IsAllVisited(vector<int>& visited)
{
    for (auto v : visited)
    {
        if (v == 0)
        {
            return false;
        }
    }
    return true;
}

void solve(int score, deque<int>& visited, vector<bool> chained, vector<vector<vector<int>>>& cost_list)
{
    if (visited.size() == chained.size())
    {
        if (result == -1) result = score;
        else result = min(result, score);
        return;
    }
    priority_queue<vector<int>> pq;
    for (auto v : visited)
    {
        for (auto costs : cost_list[v])
        {
            if (chained[costs[0]]) continue;
            pq.push({-1 * costs[1], v, costs[0]});
        }
    }
    
    if (pq.empty()) return;
    
    vector<int> top = pq.top();
    pq.pop();
    visited.push_front(top[2]);
    chained[top[2]] = true;
    
    solve(score + (-1 * top[0]), visited, chained, cost_list);
        
    visited.pop_front();
    chained[top[2]] = false;

}


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<vector<vector<int>>> cost_list(n, vector<vector<int>>());
    vector<bool> chained(n, false);
    
    for (auto cost : costs)
    {
        cost_list[cost[0]].push_back({cost[1], cost[2]});  
        cost_list[cost[1]].push_back({cost[0], cost[2]});
    }
    
    deque<int> visited;
    visited.push_front(0);
    chained[0] = true;
    solve(0, visited, chained, cost_list);
    
    
    answer = result;
    
    
    return answer;
}