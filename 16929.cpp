#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

int n, m;
bool visit[51][51] = { false, };
char map[51][51];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
bool flag = false;

void dfs(int x, int y, int sx, int sy, int direction, int cnt) {
	if (flag)
		return;

	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];

		if (tx < 0 || tx >= m || ty < 0 || ty >= n)
			continue;
		if (map[y][x] != map[ty][tx])
			continue;

		if (!visit[ty][tx]) {
			visit[ty][tx] = true;
			if (i == direction)
				dfs(tx, ty, sx, sy, direction, cnt);
			else
				dfs(tx, ty, sx, sy, i, cnt + 1);
		}
		else {
			if (tx == sx && ty == sy && cnt >= 4) {
				flag = true;
				return;
			}
		}
	}
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
			for (int k = 0; k < 4; k++) {
				memset(visit, false, sizeof(visit));
				visit[i][j] = true;
				dfs(j, i, j, i, k, 1);
				if (flag) {
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}

	cout << "No" << endl;

	return 0;
}