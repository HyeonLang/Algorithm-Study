#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool checkSkillTree(int i, int s, const string& skill, const string& skill_tree)
{
    for (int n = i + 1; n < skill.length(); n++)
    {
        if (skill[n] == skill_tree[s]) 
        {
            cout << skill[n];
            return false;
        }
        
    }
    
    return true;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for (auto skill_tree : skill_trees)
    {
        int i = 0;
        
        answer++;
        for (int s = 0; s < skill_tree.length(); s++)
        {
            if (i >= skill.length()) break;
            
            if (skill[i] == skill_tree[s])
            {
                i++;
                continue;
            }
            
            if (!checkSkillTree(i, s, skill, skill_tree)) 
            {
                cout << " : " << skill_tree << endl;
                answer--;
                break;
            }
        }
    }
    
    return answer;
}