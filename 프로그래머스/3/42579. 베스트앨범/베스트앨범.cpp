#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>

using namespace std;

struct GenreInfo
{
    int plays_count = 0;
    priority_queue<vector<int>> song_info = priority_queue<vector<int>>();
    
    bool operator<(const GenreInfo& other) const 
    {
        return plays_count < other.plays_count;
    }
};


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string, GenreInfo> songs;
    for (int i = 0; i < genres.size(); i++)
    {
        songs[genres[i]].plays_count += plays[i];
        songs[genres[i]].song_info.push({ plays[i], (-1 * i) });
    }
    
    priority_queue<GenreInfo> play_counts;
    for (auto& [key, value] : songs)
    {
        play_counts.push(value);
    }
    
    while(!play_counts.empty())
    {
        GenreInfo genre_info = play_counts.top();
        play_counts.pop();
        
        for (int i = 0; i < 2; i++)
        {
            if (genre_info.song_info.empty()) break;
            
            answer.push_back((-1 * genre_info.song_info.top()[1]));
            genre_info.song_info.pop();
        }
    }
    
    return answer;
}