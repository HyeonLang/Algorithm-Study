#include <vector>
#include <string>
#include <iostream>
using namespace std;

int dp[101][101][2];
string op[100];
int solution(vector<string> arr)
{
    int answer = -1;
    
    for (int i = 0; i < arr.size(); i++)
    {
        if (i % 2 == 1) 
        {
            op[(i / 2)] = arr[i];
        }
        else 
        {
            dp[i / 2][i / 2][0] = stoi(arr[i]);
            dp[i / 2][i / 2][1] = stoi(arr[i]);
        }
    }
    
    for (int gap = 1; gap <= arr.size() / 2; gap++)
    {
        for (int i = 0; i + gap <= arr.size() / 2; i++)
        {
            dp[i][i + gap][1] = (gap + 1) * -1001;
            dp[i][i + gap][0] = (gap + 1) * 1001;
            for (int k = i; k < i + gap; k++)
            {
                if (op[k] == "+")
                {
                    dp[i][i + gap][1] = max(dp[i][i + gap][1], dp[i][k][1] + dp[k + 1][i + gap][1]);
                    dp[i][i + gap][0] = min(dp[i][i + gap][0], dp[i][k][0] + dp[k + 1][i + gap][0]);
                }
                else
                {
                    dp[i][i + gap][1] = max(dp[i][i + gap][1], dp[i][k][1] - dp[k + 1][i + gap][0]);
                    dp[i][i + gap][0] = min(dp[i][i + gap][0], dp[i][k][0] - dp[k + 1][i + gap][1]); 
                }
            }
        }
    }
    
    answer = dp[0][arr.size() / 2][1];
    return answer;
}