#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    if (a[0] < b[0]) return true;
    if (a[0] > b[0]) return false;
    if (a[1] > b[1]) return true;
    return false;
}

int solution(vector<vector<int>> scores) {
    int answer = -1;
    vector<int> incentives;
    int ret = scores[0][0] +  scores[0][1] ;
    for (int s = 0; s < scores.size(); s++)
    {
        if (scores[0][0] < scores[s][0] && scores[0][1] < scores[s][1]) return -1;
    }
    
    sort(scores.begin(), scores.end(), compare);
    
    int max_num = 0;
    int num = 0;
    for (int i = scores.size() - 1; i >= 0; i--)
    {
        if (max_num < scores[i][1])
        {
            max_num = scores[i][1];
            num = i;
            incentives.push_back(scores[i][0] + scores[i][1]);
            continue;
        }
        
        if (max_num > scores[i][1] && scores[num][0] > scores[i][0]) continue;
        
        incentives.push_back(scores[i][0] + scores[i][1]);
    }
    
    sort(incentives.begin(), incentives.end());
    for (int i = incentives.size() - 1; i >= 0; i--)
    {

        if (incentives[i] == ret) 
            return incentives.size() - i;
    }
   
    return answer;
}