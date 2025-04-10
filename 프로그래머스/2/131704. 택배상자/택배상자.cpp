#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    
    deque<int> queue;
    
    int order_idx = 0;
    int container_idx = 1;
    while (order_idx < order.size())
    {
        if (container_idx == order[order_idx])
        {
            answer++;
            order_idx++;
            container_idx++;
        }
        else if (!queue.empty() && queue[0] == order[order_idx])
        {
            answer++;
            order_idx++;
            queue.pop_front();
        }
        else
        {
            if (container_idx > order.size()) break;
            queue.push_front(container_idx);
            container_idx++;
        }
    }
    
    return answer;
}