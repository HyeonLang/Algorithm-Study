#include <string>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
int result = 9;



int solution(int N, int number) {
    int answer = -1;
    vector<set<int>> dp(9, set<int>());
    
    int num = 0;
    for (int n = 1; n <= 8; n++)
    {
        num *= 10;
        num += N;
        
        dp[n].insert(num);
    }
        
    for (int n = 1; n <= 8; n++)
    {
        for (int i = 1; i <= n / 2; i++)
        {
            for (auto num_1 : dp[i])
            {
                for (auto num_2 : dp[n - i])
                {
                    if (num_1 + num_2 <= 32000)
                        dp[n].insert(num_1 + num_2);
                    dp[n].insert(abs(num_1 - num_2));
                    if (num_1 * num_2 <= 32000)
                        dp[n].insert(num_1 * num_2);
                    if (num_1 > num_2 && num_2 != 0)
                        dp[n].insert((int)(num_1 / num_2));
                    else if (num_1 != 0)
                        dp[n].insert((int)(num_2 / num_1));
                }
            }
        }
        
        if (dp[n].find(number) != dp[n].end())
        {
            answer = n;
            break;
        }
    }
    
    return answer;
}