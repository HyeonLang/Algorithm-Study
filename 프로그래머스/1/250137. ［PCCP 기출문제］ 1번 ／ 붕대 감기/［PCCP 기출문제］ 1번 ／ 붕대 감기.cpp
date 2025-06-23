#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    int cur_health = health;
    int attack_idx = 0;
    int bandage_time = 0;
    for (int t = 1; t <= attacks[attacks.size() - 1][0]; ++t)
    {
        if (attacks[attack_idx][0] == t)
        {
            cur_health -= attacks[attack_idx][1];
            ++attack_idx;
            bandage_time = 0;
            if (cur_health <= 0) return -1;
            continue;
        }
        
        if (++bandage_time == bandage[0]) 
        {
            cur_health += bandage[2];
            bandage_time = 0;
        }
        cur_health += bandage[1];
        
        if (cur_health > health) cur_health = health;
    }
    
    answer = cur_health;
    return answer;
}