#include <string>
#include <vector>

#define DIV 1000000007;

using namespace std;

int solution(int n) {
    int answer = 0;
    
    if (n % 2 == 1) return 0;
    
    vector<long> dp;
    for (int i = 0; i <= n; i++)
    {
        dp.push_back(0);
    }
    
    
    dp[2] = 3;
    for(int i = 4; i <= n; i += 2)
    {
        // 정방향 순서 체크
        dp[i] = (dp[i] + (dp[i - 2] * dp[2]));
        dp[i] %= 1000000007;
        
        // 정방향과 겹치지 않는 역방향 순서 체크
        for (int j = i - 4; j >= 2; j -= 2)
        {
           dp[i] = (dp[i] + (dp[j] * 2)) % 1000000007;
        }
        
        // n일때 새롭게 생기는 2개
        dp[i] += 2;  
    }
    
    answer = dp[n] % 1000000007;
    
    return answer;
}