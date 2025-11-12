#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int answer_size = 1000001;
    vector<int> seq_sum;
    int sum = 0;
    for (auto& seq : sequence)
    {
        sum += seq;
        seq_sum.push_back(sum);
    }
    
    int a = 0;
    int b = 0;
    while(b < sequence.size() && a < sequence.size())
    {
        int part;
        if (a != 0)
            part = seq_sum[b] - seq_sum[a - 1];
        else
            part = seq_sum[b];
        
        if (part == k) 
        {
            if (answer_size > b - a + 1)
            {
                answer = {a, b};
                answer_size = b - a + 1;
            }
            a++;
        }
        
        if (part > k) a++;
        else b++;
    }
    
    
    return answer;
}