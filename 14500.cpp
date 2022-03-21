#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

int ans;

int n, m;
int map[501][501];
bool visit[501][501] = { false, };

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(int x, int y, int sum, int depth) {

	if (depth == 4) {
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];

		if (tx < 0 || tx >= m || ty < 0 || ty >= n)
			continue;
		if (visit[ty][tx])
			continue;

		visit[ty][tx] = true;
		dfs(tx, ty, map[ty][tx] + sum, depth + 1);
		visit[ty][tx] = false;
	}
}

void shape1(int x, int y) { // ぬ
	int temp = 0;
	temp = map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y + 1][x + 1];
	ans = max(ans, temp);
}
void shape2(int x, int y) { // で
	int temp = 0;
	temp = map[y][x] + map[y][x + 1] + map[y - 1][x + 1] + map[y][x + 2];
	ans = max(ans, temp);
}
void shape3(int x, int y) { // た
	int temp = 0;
	temp = map[y][x] + map[y + 1][x] + map[y + 1][x + 1] + map[y + 2][x];
	ans = max(ans, temp);
}
void shape4(int x, int y) { // っ
	int temp = 0;
	temp = map[y][x] + map[y + 1][x] + map[y + 1][x - 1] + map[y + 2][x];
	ans = max(ans, temp);
}

int main(void) {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			memset(visit, false, sizeof(visit));
			visit[i][j] = true;
			dfs(j, i, map[i][j], 1);
			if (j + 2 < m) {
				if (i + 1 < n)
					shape1(j, i);
				if (i - 1 >= 0)
					shape2(j, i);
			}
			if (i + 2 < n) {
				if (j + 1 < m)
					shape3(j, i);
				if (j - 1 >= 0)
					shape4(j, i);
			}
		}
	}

	cout << ans;

	return 0;
}