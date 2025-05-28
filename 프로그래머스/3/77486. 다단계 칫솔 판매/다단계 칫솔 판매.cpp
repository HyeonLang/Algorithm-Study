#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    answer = vector<int>(enroll.size(), 0);
    
    map<string, int> enroll_index;
    for(int i = 0; i < enroll.size(); i++)
        enroll_index.insert({enroll[i], i});
    
    for (int i = 0; i < seller.size(); i++)
    {
        int sales = 100 * amount[i];
        string child_name = seller[i];
        
        while(true)
        {
            int child_index = enroll_index[child_name];
            string root_name = referral[child_index];
            
            answer[child_index] += sales;
            
            if (sales < 10) break;
            
            sales = (int)(sales * 0.1);
            answer[child_index] -= sales;
            child_name = root_name;
            
            if (root_name == "-") break;
            
        }
    }
    
    return answer;
}