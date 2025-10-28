#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> sticker)
{
    int answer =0;
    int n = sticker.size();
    vector<long> dp0(n, -1);
    vector<long> dp1(n, -1);
    
    if (n == 1) return sticker[0];
    if (n == 2) return max(sticker[0], sticker[1]);
    
    dp0[0] = 0;
    dp0[1] = sticker[1];
    
    dp1[0] = sticker[0];
    dp1[1] = dp1[0];
    
    for (int i = 2; i < n; i++)
    {
        dp0[i] = max(dp0[i - 1], dp0[i - 2] + sticker[i]);
    }
    
    for (int i = 2; i < n - 1; i++)
    {
        dp1[i] = max(dp1[i - 1], dp1[i - 2] + sticker[i]);
    }
    
    answer = max(dp0[n - 1], dp1[n - 2]);
    
    return answer;
}