#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    unordered_set<int> results;
    int all_sum = 0;
    for (auto e : elements)
        all_sum += e;
    results.insert(all_sum);
    
    for (int count = 1; count <= elements.size() / 2; count++)
    {

        for (int start = 0; start < elements.size(); start++)
        {
            int sum = 0;
            for (int i = 0; i < count; i++)
            {
                int idx = (start + i) % elements.size();
                sum += elements[idx];
            }
            
            results.insert(sum);
            results.insert(all_sum - sum);
        }
        cout << endl;
    }
    cout << endl << endl;
    answer  = results.size();
    
    return answer;
}