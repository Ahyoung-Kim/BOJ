#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

#define MAX 10001

int n;
int curr_col = 1;
int tree[MAX][2];
vector<pair<int, int>> depth_width;
int col[MAX];
int node[MAX];

void dfs(int num, int depth) {

	int left_child = tree[num][0];
	int right_child = tree[num][1];

	if (left_child == -1 && right_child == -1) { //리프 노드
		col[num] = curr_col;
	}
	else if (left_child != -1 && right_child != -1) { //둘 다
		dfs(left_child, depth + 1);
		curr_col++;
		col[num] = curr_col;
		curr_col++;
		dfs(right_child, depth + 1);
	}
	else if (left_child == -1 && right_child != -1) { //오른쪽
		col[num] = curr_col;
		curr_col++;
		dfs(right_child, depth + 1);
	}
	else if (left_child != -1 && right_child == -1) { //왼쪽
		dfs(left_child, depth + 1);
		curr_col++;
		col[num] = curr_col;
	}

	if (depth_width[depth].first == 0)
		depth_width[depth].first = num;

	depth_width[depth].second = num;
}
int main(void) {

	int ans_width = 0;
	int ans_depth = 0;

	cin >> n;

	depth_width.resize(n + 1);

	for (int i = 0; i < n; i++) {
		int p, lc, rc;

		cin >> p >> lc >> rc;

		node[p]++;
		if (lc != -1)
			node[lc]++;
		if (rc != -1)
			node[rc]++;

		tree[p][0] = lc;
		tree[p][1] = rc;
	}

	int root;
	for (int i = 1; i <= n; i++) {
		if (node[i] == 1)
			root = i;
	}

	depth_width[0] = { 0, 0 };

	dfs(root, 1);

	for (int i = 1; i < depth_width.size(); i++) {
		int left = depth_width[i].first;
		int right = depth_width[i].second;
		int width = col[right] - col[left] + 1;

		if (ans_width < width) {
			ans_width = width;
			ans_depth = i;
		}
	}

	cout << ans_depth << " " << ans_width;

	return 0;
}