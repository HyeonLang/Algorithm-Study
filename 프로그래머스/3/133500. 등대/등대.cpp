#include <string>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

void solve(int light, vector<vector<int>>& load, vector<int>& visit)
{
    visit[light] = 0;
    for (auto child : load[light])
    {
        if (visit[child] != -1) continue;
        
        solve(child, load, visit);
        
        if (visit[child] == 0) visit[light] = 1; 
    }
}


int solution(int n, vector<vector<int>> lighthouse) {
    int answer = 0;
    vector<int> visit(n + 1, -1);
    vector<vector<int>> load(n + 1, vector<int>());
    
    for (auto l : lighthouse)
    {
        load[l[0]].push_back(l[1]);
        load[l[1]].push_back(l[0]);
    }
    
    solve(1, load, visit);
    
    for (auto v : visit)
        if (v == 1) answer++;
   
    return answer;
}