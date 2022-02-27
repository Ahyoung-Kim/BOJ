#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<stack>
#include<cstring>

using namespace std;

int n, m, k;
int map[101][101] = { 0, };
bool visit[101][101] = { false, };
int ret = 0;

int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };

void dfs(int x, int y) {

	visit[y][x] = true;
	ret++;

	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];

		if (tx < 0 || tx >= n || ty < 0 || ty >= m)
			continue;
		if (visit[ty][tx] || map[ty][tx] == 1)
			continue;

		dfs(tx, ty);
	}
}

int main(void) {

	int cnt = 0;
	int x1, x2, y1, y2;
	priority_queue<int, vector<int>, greater<int>> ans;

	cin >> m >> n >> k;

	while (k > 0) {

		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = y1; i < y2; i++) {
			for (int j = x1; j < x2; j++) {
				if (map[i][j] == 0) {
					map[i][j] = 1;
				}
			}
		}

		k--;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j] && map[i][j] == 0) {
				ret = 0;
				dfs(j, i);
				cnt++;
				ans.push(ret);
			}
		}
	}

	cout << cnt << endl;
	while (!ans.empty()) {
		cout << ans.top() << " ";
		ans.pop();
	}

	return 0;
}