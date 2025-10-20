#include <string>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

struct Node 
{  
    Node(long long _num)
    {
        num = _num;
        num_ptr = &num;
    }
    long long num;
    long long* num_ptr;
};

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    
    unordered_map<long long, Node*> nodes;
    
    for (auto room : room_number)
    {
        long long n_room = room;
        
        if (nodes.find(room) != nodes.end())
        {
            n_room = *(nodes[room]->num_ptr) + 1;
            
            while(nodes.find(n_room) != nodes.end())
            {
                nodes[room]->num_ptr = nodes[n_room]->num_ptr;
                n_room = *(nodes[n_room]->num_ptr) + 1;
            }
            
            nodes[n_room] = nodes[room];
            *(nodes[n_room]->num_ptr) = n_room;

        }
        else
        {
            nodes[n_room] = new Node(n_room);
        }
        answer.push_back(n_room);
    }
    
  
    
    return answer;
}