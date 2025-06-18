#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    vector<vector<int>> results;
    map<string, int> gems_count;
    set<string> gems_set;
    for (auto gem : gems)
        if (gems_count.find(gem) == gems_count.end()) gems_count[gem] = 0;
    
    if (gems_count.size() == 1) return {1, 1};
    
    int start = 0;
    int end = 1;
    gems_set.insert(gems[0]);
    gems_count[gems[0]]++;
    
    for (; end < gems.size(); end++)
    {
        gems_count[gems[end]]++;
        gems_set.insert(gems[end]);
        while(gems_count[gems[start]] > 1)
        {
            gems_count[gems[start]]--;
            start++;
        }
        
        if (gems_set.size() == gems_count.size()) 
            results.push_back({start + 1, end + 1});
    }
    
    for (auto& result : results)
    {
        if (answer.size() == 0) answer = result;
        else
        {
            if (answer[1] - answer[0] > result[1] - result[0])
                answer = result;
        }
    }
   
    return answer;
}