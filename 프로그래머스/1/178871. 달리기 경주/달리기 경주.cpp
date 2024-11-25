#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string, int> players_rank;
    map<int, string> rank_players;
    
    int idx = 0;
    for (auto player : players)
    {
        players_rank[player] = idx;
        rank_players[idx] = player;
        idx++;
    }
    
    for (auto call_player : callings)
    {
        int call_idx = players_rank[call_player];
        string pre_player = rank_players[call_idx - 1];
        
        players_rank[call_player]--;
        players_rank[pre_player]++;
        
        rank_players[call_idx] = pre_player;
        rank_players[call_idx - 1] = call_player;
    }
    
    for (int i = 0; i < rank_players.size(); i++)
    {
        answer.push_back(rank_players[i]);
    }
    
    return answer;
}