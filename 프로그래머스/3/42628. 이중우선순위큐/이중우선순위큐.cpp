#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> calc;
    int count = 0;
    
    for (auto operation : operations)
    {
        if (operation[0] == 'I')
        {
            int num = stoi(operation.substr(2));
            calc.push_back(num);
        }
        else
        {
            if (calc.empty()) continue;
            if (operation[2] == '-')
            {
                calc.erase(min_element(calc.begin(), calc.end()));
            }
            else
            {
                calc.erase(max_element(calc.begin(), calc.end()));
            }
        }
    }
    
    if (calc.size() == 0) 
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(*max_element(calc.begin(), calc.end()));
        answer.push_back(*min_element(calc.begin(), calc.end()));
    }
   
    
    return answer;
}