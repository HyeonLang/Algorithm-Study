#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    
    vector<int> dp1(money.size());
    vector<int> dp2(money.size());
    dp1[0] = 0;
    dp1[1] = money[1];
    
    for (int i = 2; i < dp1.size(); i++)
    {
        dp1[i] = max(dp1[i - 1], dp1[i - 2] + money[i]);
    }
    
    dp2[0] = money[0];
    dp2[1] = money[0];
    
    for (int i = 2; i < dp2.size() - 1; i++)
    {
        dp2[i] = max(dp2[i - 1], dp2[i - 2] + money[i]);
    }
    
    answer = max(dp1[dp1.size() - 1] , dp2[dp2.size() - 2]);
    return answer;
}