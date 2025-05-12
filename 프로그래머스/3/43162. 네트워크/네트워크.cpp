#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <cmath>

using namespace std;


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<bool> visit(n, false);
    deque<int> stack;
    stack.push_back(0);
    visit[0] = true;
    
    while(!stack.empty())
    {
        int node = stack.front();
        stack.pop_front();
        
        
        for (int i = 0; i < n; i++)
        {
            if (computers[node][i] == 0) continue;
            if (visit[i]) continue;
            
            stack.push_front(i);
            visit[i] = true;
        }
        
       
        if (!stack.empty()) continue; 
        
        answer++;  
        for (int v = 0; v < n; v++)
        {
            if (!visit[v]) 
            {   
                stack.push_front(v);
                break;
            }
                
            
        }
    }
    
    
    return answer;
}