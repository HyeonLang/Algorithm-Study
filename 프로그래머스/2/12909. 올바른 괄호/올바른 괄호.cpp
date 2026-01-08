#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    int count = 0;
    
    for (auto& c : s)
    {
        if (c == '(')
            count++;
        else
            count--;
        
        if (count < 0) return false;
    }
    
    if (count != 0) return false;

    return answer;
}