#include <string>
#include <vector>
#include <deque>
#include <cmath>
#include <iostream>

using namespace std;

int dfs(int start, vector<vector<int>> wires, int cut_idx)
{
    int result = 0;
    
    vector<bool> visit(wires.size(), false);
    deque<int> stack;
    
    
    stack.push_front(start);
    
    while (!stack.empty())
    {
        int node = stack.front();
        stack.pop_front();
        if (visit[node]) continue;
        visit[node] = true;
        result++;
        
        for (int w = 0; w < wires.size(); w++)
        {
            if (w == cut_idx) continue;
            if (node == wires[w][0] && !visit[wires[w][1]]) 
            {
                stack.push_front(wires[w][1]);
            }
            if (node == wires[w][1] && !visit[wires[w][0]]) 
            {
                stack.push_front(wires[w][0]);
            }
        }
    }
    
    return result;
    
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    
    for (int cut_idx = 0; cut_idx < wires.size(); cut_idx++)
    {
        int line1 = dfs(wires[cut_idx][0], wires, cut_idx);
        if (line1 == n) continue;
        int line2 = dfs(wires[cut_idx][1], wires, cut_idx);
        //cout << line1 << " " << line2 << endl;
        if (line1 + line2 != n) continue;
        
        answer = min(answer, abs(line1 - line2));
    }
    
    return answer;
}