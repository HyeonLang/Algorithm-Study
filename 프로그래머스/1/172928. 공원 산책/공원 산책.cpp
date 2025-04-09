#include <string>
#include <vector>

using namespace std;

vector<int> GetDirection(char op)
{
    if (op == 'N') return {-1, 0};
    else if (op == 'E') return {0, 1};
    else if (op == 'W') return {0, -1};
    else return {1, 0}; 
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    vector<int> coordinate;
    for (int h = 0; h < park.size(); h++)
    {
        for (int w = 0; w < park[h].size(); w++)
        {
            if (park[h][w] == 'S') 
            {
                coordinate.push_back(h);
                coordinate.push_back(w);
            }
        }
    }
    
    
    for (auto route : routes)
    {
        vector<int> dir = GetDirection(route[0]);
        
        bool bCanMove = true;
        int next_h = coordinate[0];
        int next_w = coordinate[1];
            
        for (int i = 0; i < (route[2] - '0'); i++)
        {
            next_h += dir[0];
            next_w += dir[1];
            if (next_h < 0 || next_h >= park.size()) 
            {
                bCanMove = false;
                break;
            }
            if (next_w < 0 || next_w >= park[next_h].size()) 
            {
                bCanMove = false;
                break;
            }
            if (park[next_h][next_w] == 'X') 
            {
                bCanMove = false;
                break;
            }
           
        }
        
        if (bCanMove)
        {
            coordinate[0] = next_h;
            coordinate[1] = next_w;
        }
    }
    answer.push_back(coordinate[0]);
    answer.push_back(coordinate[1]);
    
    return answer;
}