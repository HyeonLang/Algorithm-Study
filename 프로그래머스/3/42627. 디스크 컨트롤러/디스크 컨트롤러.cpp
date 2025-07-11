#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    priority_queue<vector<int>> pq;
    
    sort(jobs.begin(), jobs.end());
    
    int j_idx = 0;
    int time = 0;
    vector<int> excute = {-1};
    while (j_idx < jobs.size() || !pq.empty() || excute[0] != -1)
    {
        int cur_time = 99999999;
        if (j_idx < jobs.size()) cur_time = min(cur_time, jobs[j_idx][0]);
        if (excute[0] != -1) cur_time = min(cur_time, excute[0]);
        else if (!pq.empty()) cur_time = min(cur_time, -pq.top()[1]);
        
        if (j_idx < jobs.size() && cur_time == jobs[j_idx][0])
        {
            pq.push({-jobs[j_idx][1], -cur_time, -j_idx});
            answer -= cur_time;
            j_idx++;
        }
        
        if (excute[0] != -1 && cur_time == excute[0])
        {
            answer += cur_time;
            excute[0] = {-1};
        }
        
        if (excute[0] == -1 && !pq.empty())
        {
            vector<int> top = pq.top();
            pq.pop();
            excute = {cur_time - top[0], -top[2]};
        }
    }
    cout << endl;
    
    answer /= jobs.size();
    
    return answer;
}