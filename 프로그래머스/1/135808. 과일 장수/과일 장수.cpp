#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    vector<int> scorecount(k + 1, 0);
    
    for (int i = 0; i < score.size(); i++)
    {
        scorecount[score[i]]++;
    }
    
    int idx = k;
    int count = 0;
    int maxcount = 0;
    
    while(maxcount != score.size())
    {
        while(scorecount[idx] <= 0)
        {
            idx--;
        }

        scorecount[idx]--;
        count++;
        
        if (count == m)
        {
            count = 0;
            answer += idx * m;
            
        }
        
        maxcount++;
    }
    
    return answer;
}