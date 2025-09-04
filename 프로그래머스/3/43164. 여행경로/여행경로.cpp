#include <string>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;

bool finish = false;
deque<string> result;

void solve(string cur, int count, map<string, map<string, int>>& fly, deque<string>& route)
{
    if (finish) return;
    if (count == 0)
    {
        finish = true;
        result = route;
        return;
    }
    
    //--------------------------
    
    if (fly.find(cur) == fly.end()) return;
    
    //--------------------------
    
    for (auto [airport, cnt] : fly[cur])
    {
        if (cnt == 0) continue;
        
        fly[cur][airport]--;
        route.push_back(airport);
        solve(airport, count - 1, fly, route);
        if (finish) break;
        route.pop_back();
        fly[cur][airport]++;
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    int count = tickets.size();
    
    map<string, map<string, int>> fly;
    
    deque<string> route;
    route.push_back("ICN");
    
    for(auto ticket : tickets)
    {
        fly[ticket[0]][ticket[1]]++;
    }
    
    
    solve("ICN", count, fly, route);
    
    answer.assign(result.begin(), result.end());
    
    return answer;
}