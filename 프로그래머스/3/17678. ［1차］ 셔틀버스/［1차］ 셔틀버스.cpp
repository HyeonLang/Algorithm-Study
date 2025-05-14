#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int timeStringToMinutes(string time)
{
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    
    return h * 60 + m;
}

string timeIntToString(int time)
{
    string h = to_string(time / 60);
    string m = to_string(time % 60);
    
    if (h.length() == 1) h = "0" + h;
    if (m.length() == 1) m = "0" + m;
    
    return h + ":" + m;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> minutes_table;
    
    for (auto time : timetable)
        minutes_table.push_back(timeStringToMinutes(time));
    
    sort(minutes_table.begin(), minutes_table.end());
  
    
    int bus_time = 540;
    int table_idx = 0;
    int last_minute = bus_time;
    int lastbus_count = 0;
    
    for (int i = 0; i < n; i++)
    {
        bus_time = 540 + i * t;
        lastbus_count = 0;
        
        for (int j = 0; j < m; j++)
        {
            if (table_idx == minutes_table.size()) 
            {
                last_minute = t * (n - 1) + 540;
                return timeIntToString(last_minute);
            } 
            
            if (minutes_table[table_idx] > bus_time) break;
            
            last_minute = minutes_table[table_idx];
            table_idx++;
            lastbus_count++;
        }
    }
    cout << table_idx << " " << lastbus_count << " " << last_minute << endl;
    
    if (lastbus_count < m) 
        return timeIntToString(t * (n - 1) + 540);
    
    
    answer = timeIntToString(last_minute - 1);
    cout << answer;
    
    return answer;
}