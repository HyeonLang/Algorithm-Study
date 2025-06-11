#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

string ToBinary(long long number)
{
    string result = "";
    int bi = 1;
    while(number > 0)
    {
        int mod = number % 2;
        result = to_string(mod) + result;
        number /= 2;
        if (result.length() > pow(2, bi) - 1) bi++;
    }
    
    while(result.length() < pow(2, bi) - 1)
    {
        result = '0' + result;
    }
    
    return result;
}

bool solve(string number, char parent)
{   
    int mid = number.length() / 2;
    if (parent == '0' && number[mid] == '1') return false;
    if (number.length() == 1) return true;
    
    return solve(number.substr(0, mid), number[mid]) && solve(number.substr(mid + 1, mid), number[mid]);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for (auto number : numbers)
    {
        //cout << ToBinary(number) << " ";
        if (solve(ToBinary(number), '1')) answer.push_back(1);
        else answer.push_back(0);
    }
    
    return answer;
}