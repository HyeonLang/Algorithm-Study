#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int storey) {
    int answer = 0;
    
    while (storey != 0)
    {
        int floor = storey % 10;
        if (floor > 5)
        {
            answer += (10 - floor);
            storey = storey + 10;
        }
        else if (floor == 5)
        {
            if (storey % 100 >= 50)
            {
               answer += (10 - floor);
               storey = storey + 10;
            }
            else
            {
                 answer += floor;
            }
        }
        else
        {
            answer += floor;
        }
        
        storey = storey / 10;
    }
    
    return answer;
}