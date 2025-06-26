#include <iostream>
#include <string>
#include <stack>
#include <cmath>
#include <algorithm>

using namespace std;


int solution(string s)
{
    int answer = 1;
    
    if (s.length() == 2 && s[0] == s[1]) return 2;
    
    for (int mid = 1; mid < s.length(); mid++)
    {
        int n = 1;
        int even_count = 0;
        int odd_count = 1;
        bool even = true;
        bool odd = true;
        while(mid - n >= 0 && mid + n - 1 < s.length())
        {
            if (s[mid - n] == s[mid + n - 1] && even) 
                even_count += 2;
            else even = false;
            
            if (mid + n < s.length())
            {
                if (s[mid - n] == s[mid + n] && odd)
                    odd_count += 2;
                else odd = false;
            }
            
            if (!even && !odd) break;
            n++;
        }
        answer = max(answer, even_count);
        answer = max(answer, odd_count);
    }
    
    
    return answer;
}