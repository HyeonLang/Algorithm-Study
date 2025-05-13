#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <deque>

using namespace std;
using lld = long long;

//------------------------------

int N, M, T;
vector<deque<int>> discs;

void spin(int x, int d, int k)
{
	for (int n = 1; x * n <= N; n++)
	{
		int disc = n * x;

		int count = k;
		while (count--)
		{
			int num;
			if (d == 0)
			{
				num = discs[disc - 1].back();
				discs[disc - 1].pop_back();
				discs[disc - 1].push_front(num);
			}
			else
			{
				num = discs[disc - 1].front();
				discs[disc - 1].pop_front();
				discs[disc - 1].push_back(num);
			}
		}
	}
}

double solve()
{
	vector<vector<bool>> delete_descs(N, vector<bool>(M, false));
	bool is_deleted = false;

	int sum = 0;
	int count = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (discs[i][j] == 0) continue;

			if (i == 0)
			{
				if (discs[i][j] == discs[i + 1][j]) delete_descs[i][j] = true;
			}
			else if (i == N - 1)
			{
				if (discs[i][j] == discs[i - 1][j]) delete_descs[i][j] = true;
			}
			else
			{
				if (discs[i][j] == discs[i - 1][j] || discs[i][j] == discs[i + 1][j]) delete_descs[i][j] = true;
			}
			

			if (j == 0)
			{
				if (discs[i][j] == discs[i][M - 1] || discs[i][j] == discs[i][j + 1]) delete_descs[i][j] = true;
			}
			else if (j == M - 1)
			{
				if (discs[i][j] == discs[i][j - 1] || discs[i][j] == discs[i][0]) delete_descs[i][j] = true;
			}
			else
			{
				if (discs[i][j] == discs[i][j - 1] || discs[i][j] == discs[i][j + 1]) delete_descs[i][j] = true;
			}
		}	
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			sum += discs[i][j];
			if (discs[i][j] > 0) count++;

			if (delete_descs[i][j])
			{
				discs[i][j] = 0;
				is_deleted = true;
			}
		}
	}

	if (is_deleted) return 0;
	else return (double)sum / (double)(count);
}

int main()
{
	cin >> N >> M >> T;

	for (int i = 0; i < N; i++)
	{
		deque<int> dq;
		for (int j = 0; j < M; j++)
		{
			int m;
			cin >> m;
			dq.push_back(m);
		}
		discs.push_back(dq);
	}


	for (int t = 0; t < T; t++)
	{
		int x, d, k;
		cin >> x >> d >> k;
		
		spin(x, d, k);

		double avg = solve();

		if (avg > 0)
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					if (discs[i][j] == 0) continue;

					if (discs[i][j] > avg) discs[i][j]--;
					else if (discs[i][j] < avg) discs[i][j]++;
				}
			}
		}
	}

	int result = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			result += discs[i][j];
		}
	}

	cout << result;
	return 0;
}