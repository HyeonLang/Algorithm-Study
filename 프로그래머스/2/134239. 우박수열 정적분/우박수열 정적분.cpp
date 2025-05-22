#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<double> solve(int k)
{
    vector<double> result;
    result.push_back(0);
    
    while (true)
    {
        if (k == 1) break;
        
        int pre_k = k;
        
        if (k % 2 == 0) k = k / 2;
        else k = (3 * k) + 1;
        
        double area = (double)(k + pre_k) / 2.0;
        result.push_back(area + result[result.size() - 1]);  
    }
    
    return result;
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    
    
    vector<double> integral_values = solve(k);
    int n = integral_values.size() - 1;
    
    
    for (auto range : ranges)
    {
        int a = range[0];
        int b = range[1];
        if (n + b < a) 
        {
            answer.push_back(-1);
            continue;
        }
        
        answer.push_back(integral_values[n + b] - integral_values[a]);
    }
    
    return answer;
}