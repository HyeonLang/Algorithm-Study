#include <string>
#include <vector>
#include <iostream>

using namespace std;

int result;

void solve(int& count, string compared_word, const string& alpha, const string& word)
{
    if (compared_word.length() > 5) return;
    if (compared_word == word) result = count;
    
    count++;
    for (auto c : alpha)
    {
        solve(count, compared_word + c, alpha, word); 
    }
}

int solution(string word) {
    int answer = 0;
    
    string alpha = "AEIOU";
    int count = 0;
    string compared_word = "";
    
    solve(count, compared_word, alpha, word);
    
    answer = result;
    return answer;
}