#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

void GetPermutationAlphabet(int count, int i, const string& alphabet, string& current, vector<string>& result)
{
    if (count == 0)
    {
        result.push_back(current);
        return;
    }
    
    for (int next_i = i + 1; next_i < alphabet.length(); next_i++)
    {
        string temp = current;
        current = current + alphabet[next_i];
        GetPermutationAlphabet(count - 1, next_i, alphabet, current, result);
        current = temp;
    }
}

bool Check(string A, string B)
{
    for (auto a : A)
    {
        bool is_check = false;
        for (auto b : B)
        {
            if (a == b)
            {
                is_check = true;
                break;
            }
        }
        
        if (!is_check) return false;
    }
    
    return true;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    set<string> set_answer;
    const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    for (auto order : orders)
        sort(order.begin(), order.end());
    
    for (auto n : course)
    {
        vector<string> permutation;
        string curr;
        GetPermutationAlphabet(n, -1, alphabet, curr, permutation);
        
        vector<string> max_p;
        int max_count = 2;
        for(auto p : permutation)
        {
            int count = 0;
            for (auto order : orders)
                if (Check(p, order)) count++;
            
            if (max_count < count) 
            {
                max_p = { p };
                max_count = count;
            }
            else if (max_count == count) 
            {
                max_p.push_back(p);
            }
        }
        
        for (auto p : max_p)
            answer.push_back(p);
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}