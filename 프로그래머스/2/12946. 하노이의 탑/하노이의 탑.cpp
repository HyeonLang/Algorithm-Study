#include <string>
#include <vector>

using namespace std;

void solve(int n, int from, int mid, int to, vector<vector<int>>& answer) 
{
    if (n == 0) return;
    
    vector<int> v;
    
    solve(n - 1, from, to, mid, answer);
    v.push_back(from);
    v.push_back(to);
    answer.push_back(v);
    solve(n - 1, mid, from, to, answer);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    solve(n, 1, 2, 3, answer);
    return answer;
}