#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include<iostream>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance);
    
    int top = distance;
    int row = 1;
    while(top >= row)
    {
        int remove_rocks = 0;
        int pre = 0;
        int mid = (top + row) / 2;
        for(auto rock : rocks)
        {
            if (rock - pre < mid)
            {
                remove_rocks++;
            }
            else
            {
                pre = rock;
            }
        }
        
        
        if (remove_rocks > n) 
        {
            top = mid - 1;
        }
        else 
        {
            answer = mid;
            row = mid + 1;
        }
    }
    
    return answer;
}