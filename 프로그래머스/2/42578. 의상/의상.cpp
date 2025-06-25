#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> types;
    for (auto&  unit_clothes : clothes)
        types[unit_clothes[1]]++;
    
    for (auto [type, value] : types)
        answer *= (value + 1);
    
    --answer;
    
    return answer;
}