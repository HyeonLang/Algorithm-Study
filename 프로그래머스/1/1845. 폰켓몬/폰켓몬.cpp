#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    vector<bool> hash(200000, false);
    
    for (auto num : nums)
    {
        if (!hash[num])
        {
            answer++;
            hash[num] = true;
        }
        
    }
    
    return (nums.size() / 2) < answer ? (nums.size() / 2) : answer;
}