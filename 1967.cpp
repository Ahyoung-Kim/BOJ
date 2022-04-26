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
vector<pair<int, int>> tree[MAX];
bool visit[MAX] = { false, };
int temp_sum, point;

void dfs(int u, int sum) {

	bool flag = false;

	for (int i = 0; i < tree[u].size(); i++) {
		int next = tree[u][i].first;
		if (!visit[next]) {
			if (!flag)
				flag = true;

			visit[next] = true;
			dfs(next, sum + tree[u][i].second);
		}
	}

	if (!flag) {
		if (sum > temp_sum) {
			temp_sum = sum;
			point = u;
		}
		return;
	}
}

int main(void) {

	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		tree[u].push_back({ v, w });
		tree[v].push_back({ u, w });
	}

	visit[1] = true;
	dfs(1, 0);

	memset(visit, false, sizeof(visit));
	temp_sum = 0;

	visit[point] = true;
	dfs(point, 0);

	cout << temp_sum;

	return 0;
}