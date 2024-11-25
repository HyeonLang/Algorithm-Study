#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

vector<string> Split(string str)
{
    vector<string> result;
    string split = "";
    for (auto s : str)
    {
        if (s == ' ')
        {
            if (split == "") continue;
            
            result.push_back(split);
            split = "";
            continue;
        }
        split = split + s;
    }
    result.push_back(split);
    
    return result;
}

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    map<string, map<string, int>> count;
    map<string, int> rev_count;
    map<string, int> send_count;
    priority_queue<int> result_rev;
    
    for (auto f1 : friends)
    {
        rev_count[f1] = 0;
        send_count[f1] = 0;
        for (auto f2 : friends)
        {
            count[f1][f2] = 0; 
        }
    }
    
    for (auto gift : gifts)
    {
        vector<string> str;
        str = Split(gift);
        
        send_count[str[0]]++;
        rev_count[str[1]]++;
            
        count[str[0]][str[1]]++; 
    }
    
     for (auto f1 : friends)
    {
        int result_count = 0;
         
        for (auto f2 : friends)
        {
            if (f1 == f2) continue;
            if (count[f1][f2] > count[f2][f1])
            {
                result_count++;
            }
            else if (count[f1][f2] == count[f2][f1])
            {
                if (send_count[f1] - rev_count[f1] > send_count[f2] - rev_count[f2])
                {
                    result_count++;
                }
            }
        }
        result_rev.push(result_count);
    }
    
    answer = result_rev.top();
    return answer;
}