#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<long> pq;
    bool is_overK = false;
    for (auto unit : scoville)
    {
        if (K > unit) pq.push((long)-unit);
        else is_overK = true;
    }
    
    while(!pq.empty())
    {
        if (pq.size() == 1)
        {
            if (is_overK) 
                return answer + 1;
            else 
                return -1;
            
        }
        answer++;
        long a = -pq.top();
        pq.pop();
        long b = -pq.top();
        pq.pop();
        
        long mixed = b * 2 + a;
        if (mixed >= K) 
        {
            is_overK = true;
            continue;
        }
        
        pq.push(-mixed);

    }
    
    return answer;
}