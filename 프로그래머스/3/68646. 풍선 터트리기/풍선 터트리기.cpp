#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    vector<int> min_tofirst(a.size(), 1000000001);
    vector<int> min_tolast(a.size(), 1000000001);
    
    int min_num_tofirst = 1000000001;
    int min_num_tolast = 1000000001;
    for (int i = 0; i < a.size(); i++)
    {
        min_num_tofirst = min(min_num_tofirst, a[i]);
        min_tofirst[i] = min_num_tofirst;
        
        min_num_tolast = min(min_num_tolast, a[a.size() - i - 1]);
        min_tolast[a.size() - i - 1] = min_num_tolast;
    }
    
    answer = 2;
    for (int i = 1; i < a.size() - 1; i++)
    {
        if (min_tofirst[i - 1] < a[i] && min_tolast[i + 1] < a[i])
            continue;
        answer++;
    }
    
    return answer;
}