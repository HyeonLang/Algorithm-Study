#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int result = 0;

void solve(int i, vector<int> w_idx, vector<string>& words)
{
    if (w_idx.size() == 1 || w_idx.size() == 0) return;
    
    int max_len = 0;
    //cout << i << endl;
    vector<vector<int>> letter_list(26, vector<int>());
    for (int w = 0; w < w_idx.size(); w++)
    {
        if (words[w_idx[w]].length() <= i) continue;
        int l = words[w_idx[w]][i] - 'a';
        //cout << words[w_idx[w]] << " : " << words[w_idx[w]][i] << " / ";
        letter_list[l].push_back(w_idx[w]);
        result++;
    }
    //cout << endl;
    for (auto letter : letter_list)
    {
        solve(i + 1, letter, words);
    } 
}

int solution(vector<string> words) {
    int answer = 0;
    vector<int> w_idx;
    for (int i = 0; i < words.size(); i++)
    {
        w_idx.push_back(i);
    }
    
    solve(0, w_idx, words);
    
    answer = result;
    return answer;
}