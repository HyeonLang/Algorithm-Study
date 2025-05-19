#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool visit[8] = {false};
vector<vector<int>> banned_results;


bool isCorrect(string user, string banned)
{
    if (user.length() != banned.length()) return false;
    for (int i = 0; i < user.length(); i++)
    {
        if (user[i] != banned[i] && banned[i] != '*') return false;
    }
    return true;
}

void solve(int banned_idx, vector<string>& user_id, vector<string>& banned_id)
{
    if (banned_idx >= banned_id.size())
    {
        vector<int> v;
        
        for (int i = 0; i < 8; i++)
            if (visit[i] == true) v.push_back(i); 
            
        if (v.size() != banned_id.size()) return;
        
        sort(v.begin(), v.end());
        banned_results.push_back(v);
        return;
    }
    
    for (int u = 0; u < user_id.size(); u++)
    {
        if (visit[u]) continue;
        if (!isCorrect(user_id[u], banned_id[banned_idx])) continue;
       
        visit[u] = true;
        solve(banned_idx + 1, user_id, banned_id);
        visit[u] = false;
    }
}


int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    solve(0, user_id, banned_id);
    cout << banned_results.size();
    for (int i = 0; i < banned_results.size(); i++)
    {
        answer++;
        for (int j = i + 1; j < banned_results.size(); j++)
        {
            if (banned_results[i] == banned_results[j])
            {
                banned_results.erase(banned_results.begin() + j);
                j--;
            }
        }
    }
    
    return answer;
}