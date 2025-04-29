#include <string>
#include <vector>
#include <iostream>
using namespace std;

string getNumber(int n, int num)
{
    string result = "";
    
    while(num >= n)
    {
        string remainder = "";
        if (num % n < 10)
        {
            
            remainder = to_string(num % n);
        }
        else
        {
            
            char c = 'A' + ((num % n) - 10);
            remainder += c;
        }
        
        result = remainder + result;
        num /= n;
    }
    
    if (num < 10)
    {  
        result = to_string(num) + result;
    }
    else
    {
        char c = 'A' + (num - 10);
        result = c + result;
    }
    
    
    cout << result << " ";
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    int num = 0;
    while(1)
    {
        string num_str = getNumber(n, num);
        for (auto s : num_str)
        {
            if (answer.length() == t) return answer;
            if (p == 1)
            {
                answer = answer + s;
                p = m;
            } else {
                p--;
            }
        }
        num++;
    }
    
}