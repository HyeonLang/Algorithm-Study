#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int target) {
    vector<int> answer;
    vector<int> dp_score(target + 1, 100001);
    vector<int> dp_sb(target + 1, 0);
    for (int i = 1; i <= 20 && i <= target; ++i)
    {
        dp_score[i] = 1;
        dp_sb[i] = 1;
        if (i*2 <= target)
            dp_score[i*2] = 1;
        if (i*3 <= target)
            dp_score[i*3] = 1;
    }
    if (target >= 50)
    {
        dp_score[50] = 1;
        dp_sb[50] = 1;
    }
    
    for (int i = 1; i <= target; ++i)
    {
        if (dp_score[i] != 100001) continue;
        
        for (int j = 1; j <= i / 2; ++j)
        {
            int count = dp_score[j] + dp_score[i - j];
            int sb = dp_sb[j] + dp_sb[i - j];
            
            if (dp_score[i] > count)
            {
                dp_score[i] = count;
                dp_sb[i] = sb;
            }
            else if (dp_score[i] == count && dp_sb[i] < sb)
            {
                dp_sb[i] = sb;
            }
        }
    }
    
    answer = {dp_score[target], dp_sb[target]};
    return answer;
}