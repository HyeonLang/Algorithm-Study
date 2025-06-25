#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long max_time = 1e18;
    
    long long min_time = 1;
    
    while(max_time >= min_time)
    {
        long long mid = (max_time + min_time) / 2;
        long long process_n = 0;
        for (auto time : times)
        {
            process_n += mid / time;
        }
        if (n <= process_n)
        {
            max_time = mid - 1;
            answer = mid;
        }
        if (n > process_n) min_time = mid + 1;
        
    }
        
    return answer;
}