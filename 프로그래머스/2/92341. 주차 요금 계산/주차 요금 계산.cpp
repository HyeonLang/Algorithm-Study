#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int CalcTime(string InTime, string OutTime)
{
    int hour, minute;
    hour = stoi(OutTime.substr(0,2)) - stoi(InTime.substr(0,2));
    minute = (stoi(OutTime.substr(3,5)) + 60) - stoi(InTime.substr(3,5));
    
    if (minute < 60)
    {
        hour--;
    }
    else
    {
        minute = minute % 60;
    }
    
    //if (result_time <= fees[0]) return fees[1];
    
    //float unit_fee = ceil((result_time - (float)fees[0]) / (float)fees[2]);
    return hour * 60 + minute;
}

int CalcFee(vector<int> fees,int time)
{
    if (time <= fees[0]) return fees[1];
    float unit_time = ceil(((float)time - (float)fees[0]) / (float)fees[2]);
    return (int)(fees[1] + unit_time * fees[3]);
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    string car_in[10000];
    int car_time[10000] = {};
    bool isCar[10000] = { false };
    
    
    for (int i = 0; i < 10000; i++)
    {
        car_in[i] = "";
    }
    
    
    for (auto record : records)
    {
        if (record.substr(11, 13) == "IN")
        {
            string intime = record.substr(0, 5);
            int car_num = stoi(record.substr(6, 10));
            car_in[car_num] = intime;
            isCar[car_num] = true;
        }
        else
        {
            string outtime = record.substr(0, 5);
            int car_num = stoi(record.substr(6, 10));
            car_time[car_num] += CalcTime(car_in[car_num], outtime);
            car_in[car_num] = "";
        }
    }
    
    
    
    for (int i = 0; i < 10000; i++)
    {
        if (car_in[i] != "") 
        {
            car_time[i] += CalcTime(car_in[i], "23:59");
            car_in[i] = "";
        }
        if (isCar[i]) answer.push_back(CalcFee(fees, car_time[i]));
    }
    
    return answer;
}