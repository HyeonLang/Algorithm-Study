#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <deque>
#include <map>

using namespace std;
using lld = long long;

//------------------------------

int N;


struct Node
{
	int idx;
	int left_count;
	int right_count;
	int left;
	int right;
	int level;
	int pos;
};

int CountChild(int node, int level, int& max_level, vector<Node>& nodes)
{
	Node& root = nodes[node];
	root.level = level;
	max_level = max(max_level, level);

	if (root.left < 0) root.left_count = 0;
	else root.left_count = CountChild(root.left, level + 1, max_level, nodes);

	if (root.right < 0) root.right_count = 0;
	else root.right_count = CountChild(root.right, level + 1, max_level, nodes);
	
	return root.left_count + root.right_count + 1;
}

void SetPos(int node, vector<Node>& nodes)
{
	Node& root = nodes[node];

	if (root.left >= 0)
	{
		nodes[root.left].pos = root.pos - nodes[root.left].right_count - 1;
		SetPos(root.left, nodes);
	}
	
	if (root.right >= 0)
	{
		nodes[root.right].pos = root.pos + nodes[root.right].left_count + 1;
		SetPos(root.right, nodes);
	}
	
}

bool compare(Node a, Node b)
{
	if (a.idx < b.idx) return true;
	return false;
}

int main()
{
	cin >> N;
	vector<Node> nodes;
	int max_level = 0;
	vector<bool> IsChild(N, false);
	for (int n = 0; n < N; n++)
	{
		int idx, left, right;
		cin >> idx >> left >> right;
		if (left - 1 >= 0) IsChild[left - 1] = true;
		if (right - 1 >= 0) IsChild[right - 1] = true;
		
		nodes.push_back({idx - 1, 0, 0, left - 1, right - 1, 0, 0});
	}

	sort(nodes.begin(), nodes.end(), compare);

	int root = 0;
	int level = 1;

	for (int i = 0; i < N; i++)
		if (!IsChild[i]) root = i;
	
	CountChild(root, level, max_level, nodes);
	SetPos(root, nodes);
	

	vector<vector<int>> level_pos(max_level + 1, vector<int>({10001, -10001}));
	map<int, int> max_pos;
	for (auto& node : nodes)
	{
		level_pos[node.level][0] = min(level_pos[node.level][0], node.pos);
		level_pos[node.level][1] = max(level_pos[node.level][1], node.pos);
	}
	
	int result_level = 1;
	int result_width = -1;

	for (int i = 1; i <= max_level; i++)
	{
		int width = level_pos[i][1] - level_pos[i][0] + 1;
		if (result_width < width)
		{
			result_level = i;
			result_width = width;
		}
	}
	cout << result_level << " " << result_width;

	return 0;
}