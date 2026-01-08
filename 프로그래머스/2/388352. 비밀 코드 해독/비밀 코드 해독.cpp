#include <string>
#include <vector>
#include <set>

using namespace std;

void create_all_code(int depth, int last_num, int& n, set<int>& code, vector<set<int>>& codes)
{
    if (depth == 5)
    {
        codes.push_back(code);
        return;
    }
    
    for (int i = last_num + 1; i <= n - 4 + depth; i++)
    {
        code.insert(i);
        create_all_code(depth + 1, i, n, code, codes);
        code.erase(i);
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    vector<set<int>> codes;
    set<int> temp_code;
    create_all_code(0, 0, n, temp_code, codes);
    
    for (auto& code : codes)
    {
        bool correct = true;
        
        for (int i = 0; i < q.size(); i++)
        {
            int count = 0;
            for (int j = 0; j < q[i].size(); j++)
                if (code.find(q[i][j]) != code.end()) count++;
            
            if (count != ans[i]) 
            {
                correct = false;
                break;
            }
        }
        
        if (correct) answer++;
    }
    
    
    return answer;
}