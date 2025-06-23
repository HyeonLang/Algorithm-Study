#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

int solution(std::vector<int> a) {
    int answer = 0;
    
    if (a.size() == 1) return answer;
    
    unordered_map<int, int> nums;
    for (auto num : a)
        nums[num]++;
    
    for (auto [num, count] : nums)
    {
        int len = 0;
        if (count * 2 < answer) continue;
        for (int i = 0; i < a.size() - 1; i++)
        {
            
            if (count == 0) break;
            if (a[i] == num && a[i + 1] != a[i])
            {
                count--;
                len += 2;
                i++;
            }
            else if (a[i + 1] == num && a[i] != a[i + 1])
            {
                count--;
                len += 2;
                i++;
            }
        }   
        answer = max(answer, len);
    }
    
    return answer;
}