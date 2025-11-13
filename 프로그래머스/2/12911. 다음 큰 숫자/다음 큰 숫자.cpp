#include <string>
#include <vector>
#include <bitset>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    
    bitset<32> bn(n);
    string s_bn = bn.to_string();

    int i;
    int count = -1;
    if (s_bn[s_bn.size() - 1] == '1') count++;
    
    for (i = s_bn.size() - 2; i >= 0; i--)
    {
        if (s_bn[i] == '0' && s_bn[i + 1] == '1')
            break;
        if (s_bn[i] == '1') count++;
    }
    s_bn[i] = '1';
    s_bn[i + 1] = '0';
    i++;
    
    for (int j = s_bn.size() - 1; j > i; j--)
    {
        if (count > 0)
            s_bn[j] = '1';
        else
            s_bn[j] = '0';
        count--;
    }
    
    bitset<32> b_r(s_bn);
    answer = (int)(b_r.to_ulong());
    return answer;
}