#include <string>
#include <vector>

using namespace std;

int GetYearning(vector<string>& name, vector<int>& yearning, string photo_name)
{
    for (int i = 0; i < name.size(); i++)
    {
        if (name[i] == photo_name)
        {
            return yearning[i];
        }
    }
    
    return 0;
}

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    for (auto p : photo)
    {   
        int result_yearning = 0;
        for (auto photo_name : p)
        {
            result_yearning += GetYearning(name, yearning, photo_name);
        }
        answer.push_back(result_yearning);
    }
    
    return answer;
}