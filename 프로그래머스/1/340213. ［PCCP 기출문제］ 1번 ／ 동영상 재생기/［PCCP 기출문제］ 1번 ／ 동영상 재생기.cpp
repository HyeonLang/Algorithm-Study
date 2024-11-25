#include <string>
#include <vector>

using namespace std;

int makeTime(string str) 
{
    int minute = stoi(str.substr(0,2));
    int second = stoi(str.substr(3,2));
    
    int ret = (minute * 60) + second;
                     
    return ret;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int video_time = makeTime(video_len);
    int pos_time = makeTime(pos);
    int op_start_time = makeTime(op_start);
    int op_end_time = makeTime(op_end);
    
    if (pos_time <= op_end_time && pos_time >= op_start_time)
    {
        pos_time = op_end_time;
    }
    
    for (auto command : commands)
    {
        if (command == "prev")
        {
            pos_time -= 10;
            if (pos_time < 0) pos_time = 0;
        }
        else 
        {
            pos_time += 10;
            if (pos_time > video_time) pos_time = video_time;
        }
        
        if (pos_time <= op_end_time && pos_time >= op_start_time)
        {
            pos_time = op_end_time;
        }
    }
    
    string minute = to_string(pos_time / 60);
    string second = to_string(pos_time % 60);
    if (pos_time / 60 < 10) minute = "0" + minute;
    if (pos_time % 60 < 10) second = "0" + second;
    answer = minute + ":" + second;
    
    return answer;
}