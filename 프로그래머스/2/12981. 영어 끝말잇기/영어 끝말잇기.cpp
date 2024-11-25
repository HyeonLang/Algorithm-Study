#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    answer.push_back(0);
    answer.push_back(0);
    
    
    for (int i = 1; i < words.size(); i++)
    {
        if (words[i - 1][words[i - 1].length() - 1] != words[i][0])
        {
            int man = (i + 1) % n;
            if (man == 0) man = n;
            
            int num = (i / n) + 1;
            
            answer[0] = man;
            answer[1] = num;
            
            return answer;
        }
        
        for (int j = 0; j < i; j++)
        {
            if (words[j] == words[i])
            {
                int man = (i + 1) % n;
                if (man == 0) man = n;
            
                int num = (i / n) + 1;
            
                answer[0] = man;
                answer[1] = num;
                
                return answer;
            }
        }
    }
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다. 
    // cout << words[i - 1][words[i - 1].length() - 1] << endl;

    return answer;
}