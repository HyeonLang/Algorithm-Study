#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for (int y_c = 1; y_c <= sqrt(yellow); y_c++)
    {
        if (yellow % y_c != 0) continue;
        int y_r = yellow / y_c;
        //cout << y_r << " " << y_c << endl;
        if (y_r * 2 + y_c * 2 + 4 == brown)
        {
            answer.push_back(y_r + 2);
            answer.push_back(y_c + 2);
            break;
        }
    }
    
    return answer;
}