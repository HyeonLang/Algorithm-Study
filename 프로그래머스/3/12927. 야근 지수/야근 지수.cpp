#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    
    for (auto work : works)
        pq.push(work);
    
    while(n--)
    {
        if (pq.top() == 0) break;
        
        pq.push(pq.top() - 1);
        pq.pop();
    }
    
    while(!pq.empty())
    {
        answer += pq.top() * pq.top();
        pq.pop();
    }
    
    return answer;
}