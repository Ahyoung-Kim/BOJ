#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<stack>
#include<cstring>
#include<stdio.h>
#include<math.h>

using namespace std;

int map[101][101];
bool visit[101][101] = { false, };
int n;
int maxh = 0;
int minh = 101;

int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };

void dfs(int x, int y, int h) {

	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];

		if (tx < 0 || tx >= n || ty < 0 || ty >= n)
			continue;

		if (visit[ty][tx])
			continue;

		if (map[ty][tx] <= h)
			continue;

		visit[ty][tx] = true;
		dfs(tx, ty, h);
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	int cnt = 0;
	int ans = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];

			maxh = max(maxh, map[i][j]);
			minh = min(minh, map[i][j]);
		}
	}

	if (maxh == 1) {
		cout << 0;
		return 0;
	}

	for (int h = minh; h < maxh; h++) {

		cnt = 0;

		memset(visit, false, sizeof(visit));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visit[i][j] && map[i][j] > h) {
					visit[i][j] = true;
					dfs(j, i, h);
					cnt++;
				}
			}
		}

		ans = max(ans, cnt);
	}


	cout << ans;


	return 0;
}