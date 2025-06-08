#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    
    priority_queue<int> pq;
    for (auto b : B)
        pq.push((-1 * b));
    
    for (auto a : A)
    {
        while(!pq.empty() && a >= -1 * pq.top())
        {
            pq.pop();
        }
        
        if (pq.empty()) break;
        
        answer++;
       // cout << a <<  ", " << -1 * pq.top() << endl;
        pq.pop();
       
    }
    
    return answer;
}