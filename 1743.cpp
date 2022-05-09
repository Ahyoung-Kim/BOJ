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

int n, m, k;
int map[101][101] = { 0, };
bool visit[101][101] = { false, };
int ans;
int cnt;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(int x, int y) {
	cnt++;

	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx<1 || tx>m || ty<1 || ty>n)
			continue;
		if (visit[ty][tx] || map[ty][tx] == 0)
			continue;
		visit[ty][tx] = true;
		dfs(tx, ty);
	}
}

int main(void) {

	cin >> n >> m >> k;

	for (int i = 0; i < k; i++) {
		int r, c;
		cin >> r >> c;
		map[r][c] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!visit[i][j] && map[i][j] == 1) {
				cnt = 0;
				visit[i][j] = true;
				dfs(j, i);
				ans = max(ans, cnt);
			}
		}
	}
	cout << ans;

	return 0;
}