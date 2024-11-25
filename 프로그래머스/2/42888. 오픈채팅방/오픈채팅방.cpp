#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> Split(string str)
{
    vector<string> result;
    string s = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            result.push_back(s);
            s = "";
            continue;
        }
        s += str[i];
    }
    result.push_back(s);
    
    return result;
}



vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<vector<string>> spritrecord;
    map<string, string> uidname;
    
    for (auto r : record)
    {
        vector<string> s;
        s = Split(r);
        spritrecord.push_back(s);
        
        if (s.size() > 2)
        {
            uidname[s[1]] = s[2];
        }
    }
    
    for (auto s : spritrecord)
    {
         if (s[0] == "Enter")
        {
            string str;
            str = uidname[s[1]] + "님이 들어왔습니다.";
            answer.push_back(str);
        }
        else if (s[0] == "Leave")
        {
            string str;
            str = uidname[s[1]] + "님이 나갔습니다.";
            answer.push_back(str);
        }
    }
    
    return answer;
}