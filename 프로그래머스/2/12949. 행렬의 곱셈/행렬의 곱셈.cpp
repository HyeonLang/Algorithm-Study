#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    vector<int> arr1_sum;
    vector<int> arr2_sum;
    
    
    
    for (int r1 = 0; r1 < arr1.size(); r1++)
    {
        vector<int> temp;
        for (int c2 = 0; c2 < arr2[0].size(); c2++)
        {
            int sum = 0;
            for (int t = 0; t < arr1[r1].size(); t++)
            {
                sum += arr1[r1][t] * arr2[t][c2];
            }
            temp.push_back(sum);
        }
        answer.push_back(temp);
    }
    
    return answer;
}