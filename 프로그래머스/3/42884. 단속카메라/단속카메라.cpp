#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int result = 99999999;
bool compare(vector<int> a, vector<int> b)
{
    if (a[1] > b[1]) return false;
    
    return true;
}

void solve(int i, int count, vector<bool>& visit, vector<vector<int>>& routes)
{
    if (i >= routes.size())
    {
        result = min(result, count);
        return;
    }
    
    visit[i] = true;
    int start;
    for (start = i + 1; start < routes.size(); start++)
    {
        if (routes[start][0] > routes[i][1] || routes[start][1] < routes[i][1]) break;
        visit[start] = true;
    }
    
    solve(start, count + 1, visit, routes);
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), compare);
    vector<bool> visit(routes.size(), false);
    solve(0, 0, visit, routes);
    
    answer = result;
    return answer;
}