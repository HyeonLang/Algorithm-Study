#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool comp(vector<int> v1, vector<int> v2)
{
    if (v1[0] == v2[0]) return v1[1] < v2[1];
    return v1[0] < v2[0];
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    long long extime = 0;
    long long total_time = 0;
    int max_level = *max_element(diffs.begin(), diffs.end());
    int min_level = 1;
    int level = 1;

    while(true)
    {
        level = (max_level + min_level) / 2;
        total_time = 0;
        
        for (int i = 0; i < diffs.size(); i++)
        {
            total_time += times[i];
            if (level < diffs[i])
                total_time += (times[i] + times[i - 1]) * (diffs[i] - level);
                
        }
        
        if (total_time > limit) min_level = level + 1;
        else max_level = level - 1;
        
        if (max_level < min_level) break;
    }
    
  
    answer = min_level;
    return answer;
}