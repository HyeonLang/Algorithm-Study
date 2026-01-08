#include <string>
#include <vector>
#include <deque>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    deque<int> q(bridge_length, 0);
    int cur_weight = 0;
    int end_truck = 0;
    int idx = 0;
    while (end_truck < truck_weights.size())
    {
        answer++;
        
        cur_weight -= q.front();
        if (q.front() != 0) end_truck++;
        q.pop_front();
        
        if (idx >= truck_weights.size()) continue;
        
        if (cur_weight + truck_weights[idx] > weight) 
        {
            q.push_back(0);
            continue;
        }
        
        q.push_back(truck_weights[idx]);
        cur_weight += truck_weights[idx];
        idx++;
    }
    
    return answer;
}