#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <deque>

using namespace std;
using lld = long long;

//------------------------------

int N;
int space[21][21];
int result_time = 0;
pair<int, int> curr;

int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

bool IsValidIndex2D(int r, int c)
{
	if (r < 0 || r >= N) return false;
	if (c < 0 || c >= N) return false;

	return true;
}

vector<pair<int, int>> FindFishes(int curr_size)
{
	vector<pair<int, int>> v;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			if (space[r][c] < curr_size && space[r][c] != 0)
			{
				v.push_back(make_pair(r, c));
			}
		}
	}

	return v;
}

int GetDistance(pair<int, int> curr, pair<int, int> target, int curr_size)
{
	deque<pair<int, int>> q;
	deque<int> q_time;
	q_time.push_back(0);
	q.push_back(curr);
	vector<vector<bool>> visit(N, vector<bool>(N, false));
	visit[curr.first][curr.second] = true;

	while (!q.empty())
	{
		pair<int, int> fish = q.front();
		int time = q_time.front();
		q_time.pop_front();
		q.pop_front();

		if (target == fish) return time;

		for (auto d : dir)
		{
			int next_r = fish.first + d[0];
			int next_c = fish.second + d[1];

			if (!IsValidIndex2D(next_r, next_c)) continue;
			if (visit[next_r][next_c]) continue;
			if (space[next_r][next_c] > curr_size) continue;
			
			visit[next_r][next_c] = true;
			q.push_back(make_pair(next_r, next_c));
			q_time.push_back(time + 1);
		}

	}

	return -1;
}


bool compare(vector<int> a, vector<int> b)
{
	if (a[0] < b[0]) return true;
	if (a[0] > b[0]) return false;
	
	if (a[1] < b[1]) return true;
	if (a[1] > b[1]) return false;

	if (a[2] < b[2]) return true;
	else return false;
}


int main()
{
	cin >> N;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			cin >> space[r][c];
			if (space[r][c] == 9)
			{
				curr.first = r;
				curr.second = c;
				space[r][c] = 0;
			}
		}
	}

	int curr_size = 2;
	int curr_count = 0;
	
	while (1)
	{
		vector<vector<int>> fishes_dis;

		vector<pair<int, int>> fishes = FindFishes(curr_size);

	
		for (auto fish : fishes)
		{
			int distance = GetDistance(curr, fish, curr_size);
			if (distance == -1) continue;

			vector<int> v;
			v.push_back(distance);
			v.push_back(fish.first);
			v.push_back(fish.second);

			fishes_dis.push_back(v);
		}

		if (fishes_dis.size() == 0) break;
		sort(fishes_dis.begin(), fishes_dis.end(), compare);
		

		curr_count++;
		space[fishes_dis[0][1]][fishes_dis[0][2]] = 0;
		curr.first = fishes_dis[0][1];
		curr.second = fishes_dis[0][2];
		result_time += fishes_dis[0][0];

		if (curr_count == curr_size)
		{
			curr_size++;
			curr_count = 0;
		}
	}

	cout << result_time;
	return 0;
}