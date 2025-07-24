#include <string>
#include <vector>
#include <deque>
#include <list>
#include <iostream>

using namespace std;




string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'O');
    
    vector<vector<int>> v;
    deque<int> d_s;
    for (int i = 0; i < n; i++)
    {
        v.push_back({1, i - 1, i + 1});
    }
    
    for(auto& s : cmd)
    {
        if (s[0] == 'U')
        {
            int num = stoi(s.substr(2));
            while (num--)
            {
                k = v[k][1];
            }
        }
        else if (s[0] == 'D')
        {
            int num = stoi(s.substr(2));
            while (num--)
            {
                k = v[k][2];
            }
        }
        else if (s[0] == 'C')
        {
            int pre = v[k][1];
            int next = v[k][2];
            
            if (pre > -1) v[pre][2] = next;
            if (next < n) v[next][1] = pre;
            v[k][0] = 0;
            d_s.push_front(k);
            if (next == n) k = pre;
            else k = next;
        }
        else if (s[0] == 'Z')
        {
            int top = d_s.front();
            d_s.pop_front();
            v[top][0] = 1;
            int pre = v[top][1];
            int next = v[top][2];
            
            if (pre > -1) v[pre][2] = top;
            if (next < n) v[next][1] = top;
        }
    }
    
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i][0] == 0) answer[i] = 'X';
    }
   
    return answer;
}