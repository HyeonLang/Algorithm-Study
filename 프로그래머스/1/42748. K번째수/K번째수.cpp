#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (auto command : commands)
    {
        vector <int> splited;
        for (int i = command[0] - 1; i < command[1]; i++)
        {
            splited.push_back(array[i]);
        }
        sort(splited.begin(), splited.end());
        
        answer.push_back(splited[command[2] - 1]);
    }
    
    return answer;
}