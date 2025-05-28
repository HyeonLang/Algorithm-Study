#include <string>
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    
    vector<vector<int>> logs;
    cout << fixed << setprecision(3);
    for (auto line : lines)
    {
        string s = line.substr(11);
        string t = s.substr(13);
        t.pop_back();
        int finish_time = round(stod(s.substr(0, 2))*1000.0) * 3600 + round(stod(s.substr(3, 2))*1000.0) * 60 + round(stod(s.substr(6, 6)) * 1000.0) + 10000;      
        int p_time = round(stod(t) * 1000.0);
        int start_time = finish_time - p_time + 1;
        
        logs.push_back({start_time, finish_time});
    }
    
    int start_line;
    int end_line;
    
    for (int i = 0; i < logs.size(); i++)
    {
        start_line = logs[i][1];
        end_line = start_line + 999;
        int count = 0;
     
        
        for(int j = i; j < logs.size(); j++)
        {
            if (logs[j][0] <= end_line) count++;
           
        }

        answer = max(answer, count); 
    }
    
    return answer;
}