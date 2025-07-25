#include <string>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

vector<int> bfs(int start, int& depth, vector<vector<int>>& lists)
{
    vector<int> result;
    depth = 0;
    
    int n = lists.size();
    vector<bool> visit(n, false);
    
    deque<vector<int>> q;
    q.push_back({start, 0});
    visit[start] = true;
    while(!q.empty())
    {
        vector<int> top = q.front();
        q.pop_front();
        
        bool is_leaf = true;
        for (auto& l : lists[top[0]])
        {
            if (visit[l]) continue;
            visit[l] = true;
            is_leaf = false;
            q.push_back({l, top[1] + 1});
        }
        
        if (!is_leaf) continue;
        
        if (depth < top[1])
        {
            depth = top[1];
            result.clear();
            result.push_back(top[0]);
        }
        else if (depth == top[1])
        {
            result.push_back(top[0]);
        }
    }
    
    return result;
}

int solution(int n, vector<vector<int>> edges) {
    int answer = 0;
    vector<vector<int>> lists(n + 1, vector<int>());
    for (auto edge : edges)
    {
        lists[edge[0]].push_back(edge[1]);
        lists[edge[1]].push_back(edge[0]);
    }
    
    int depth = 0;
    vector<int> node = bfs(1, depth, lists);
    
    vector<int> node2 = bfs(node[0], depth, lists);
    if (node2.size() > 1) return depth;
    
    vector<int> node3 = bfs(node2[0], depth, lists);
    if (node3.size() > 1) return depth;
    else return depth - 1;
    
    return answer;
}