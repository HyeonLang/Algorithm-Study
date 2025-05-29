#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;
    int n = cookie.size();
    for (int m = 0; m < n - 1; m++)
    {
        int l = m;
        int r = m + 1;
        int l_count = cookie[l];
        int r_count = cookie[r];
        while(true)
        {
            //cout << l_count << ":" << r_count << " / ";
            if (l_count == r_count) answer = max(answer, l_count);
            
            if (l_count <= r_count && l > 0) 
            {
                l--;
                l_count += cookie[l];
            }
            else if (l_count > r_count && r < n - 1) 
            {
                r++;
                r_count += cookie[r];
            }
            else break;
        }
        //cout << endl;
    }
    
    return answer;
}