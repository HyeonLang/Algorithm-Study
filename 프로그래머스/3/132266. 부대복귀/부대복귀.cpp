#include <string>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    vector<vector<int>> roads_list(n, vector<int>());
    
    for (auto road : roads)
    {
        roads_list[road[0] - 1].push_back(road[1] - 1);
        roads_list[road[1] - 1].push_back(road[0] - 1);
    }
    
    vector<int> distance(n, -1);
    distance[destination - 1] = 0;
    
    deque<vector<int>> q;
    q.push_back({destination - 1, 0});
    
    while(!q.empty())
    {
        vector<int> now = q.front();
        q.pop_front();
        
        for (auto node : roads_list[now[0]])
        {
            if (distance[node] != -1) continue;
            distance[node] = now[1] + 1;
            q.push_back({node, now[1] + 1});
        }
    }
    
    for (auto source : sources)
        answer.push_back(distance[source - 1]);
    
    return answer;
}