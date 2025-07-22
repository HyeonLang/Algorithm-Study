#include <string>
#include <vector>
#include <iostream>

using namespace std;

int stoi_time(string s)
{
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    int sec = stoi(s.substr(6, 2));
    
    return h * 3600 + m * 60 + sec;
}

string to_string_time(int n)
{
    int h = n / 3600;
    int m = (n % 3600) / 60;
    int s = n % 60;
    
    string s_h = to_string(h);
    if (s_h.size() == 1) s_h = "0" + s_h;
    string s_m = to_string(m);
    if (s_m.size() == 1) s_m = "0" + s_m;
    string s_s = to_string(s);
    if (s_s.size() == 1) s_s = "0" + s_s;
    
    return s_h + ":" + s_m + ":" + s_s;
}
string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    
    int p_time = stoi_time(play_time);
    int ad_time = stoi_time(adv_time);
    
    vector<int> time_count(p_time + 1, 0);
    vector<int> total_count(p_time + 1, 0);
    
    for (auto& log : logs)
    {
        int start = stoi_time(log.substr(0, 8));
        int end = stoi_time(log.substr(9, 8));
        
        time_count[start]++;
        time_count[end]--;
    }
    
    int c = 0;
    for (int i = 0; i < total_count.size(); i++)
    {
        c += time_count[i];
        total_count[i] = c;
        //if (time_count[i] != 0)
            //cout << total_count[i] << " " << to_string_time(i) << endl;
    }
    
    long max_time = 0;
    int clock = 0;
    for (int i = 0; i <= p_time - ad_time; i++)
    {
        long time = 0;
        for (int j = i; j < ad_time + i; j++)
        {
            time += (long)total_count[j];
        }
        
        if (max_time < time)
        {
            max_time = time;
            clock = i;
        }
    }
    //cout << to_string_time(max_time) << " " << max_time << endl;
    answer = to_string_time(clock);
    
    return answer;
}