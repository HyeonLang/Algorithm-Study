/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> buildings;

int solve()
{
    int result = 0;

    for (int i = 2; i < buildings.size() - 2; i++)
    {
        int hightBefore = max(buildings[i - 2], buildings[i - 1]);
        int hightNext = max(buildings[i + 2], buildings[i + 1]);
        int hight = max(hightBefore, hightNext);

        if (buildings[i] > hight)
        {
            result += buildings[i] - hight;
        }
    }

    return result;
}

int main() {

    for (int C = 0; C < 10; C++)
    {
        cin >> N;

        for (int n = 0; n < N; n++)
        {
            int h;
            cin >> h;
            buildings.push_back(h);
        }

        int result = solve();
        cout << "#" << C + 1 << " " << result << endl;
        buildings.clear();

    }

    return 0;
}
