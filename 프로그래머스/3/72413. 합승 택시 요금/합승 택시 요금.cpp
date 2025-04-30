#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int INF = 20000001;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    
    int nodes[201][201];
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            nodes[i][j] = (i == j) ? 0 : INF;
        
    for (auto fare : fares)
    {
        nodes[fare[0]][fare[1]] = fare[2];
        nodes[fare[1]][fare[0]] = fare[2];
    }
    
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                nodes[i][j] = min(nodes[i][j], nodes[i][k] + nodes[k][j]);
  
    
    for (int k = 1; k <= n; k++)
        answer = min(answer, nodes[s][k] + nodes[k][a] + nodes[k][b]);  
    
    
    return answer;
}