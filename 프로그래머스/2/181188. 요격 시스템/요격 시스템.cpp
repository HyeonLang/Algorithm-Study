#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp(vector<int> &v1, vector<int> &v2)
{
    if (v1[0] == v2[0]) return v1[1] < v2[1];
    return v1[0] < v2[0];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    vector<int> target;
    
    sort(targets.begin(), targets.end(), comp);
    int end = targets[0][1];
    
    for (int i = 1; i < targets.size(); i++)
    {
        if (end <= targets[i][0]) 
        {
            answer++;
            end = targets[i][1];
        }
        else
        {
            if (end > targets[i][1]) end = targets[i][1];
        }
    }
    answer++;
    
    return answer;
}