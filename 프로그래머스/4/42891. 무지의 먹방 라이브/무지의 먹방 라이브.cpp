#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    vector<bool> eat(food_times.size(), false);
    priority_queue<vector<int>> pq;
    for (int i = 0; i < food_times.size(); i++)
    {
        pq.push({-food_times[i], i});
    }
    
    int pre_time = 0;
    
    long long t = ((long long)pq.size() * (long long)(-pq.top()[0] - pre_time));
        
    while(k >= t && !pq.empty())
    {
        k -= t;
        pre_time = -pq.top()[0];
        while (!pq.empty() && pre_time == -pq.top()[0])
        {
            eat[pq.top()[1]] = true;
            pq.pop(); 
        }
        
        if (pq.empty()) return -1;
        t = ((long long)pq.size() * (long long)(-pq.top()[0] - pre_time));
    }
    
    if (pq.empty()) return -1;
    k = k % pq.size();
    
    int idx = 0;
    while(true)
    {
        if (eat[idx]) 
        {
            idx = idx + 1;
            continue;
        }
        if (k == 0) break;
        idx = idx + 1;
        k--;
    }
    
    answer = idx + 1;
    
    return answer;
}