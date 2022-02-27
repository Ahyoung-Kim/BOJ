#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<stack>
#include<cstring>

using namespace std;

int w, h;
int map[51][51];
bool visit[51][51] = { false, };

int dx[8] = { 1, 0, 0, -1, -1, 1, 1, -1 };
int dy[8] = { 0, 1, -1, 0, -1 , -1, 1, 1 };

void dfs(int x, int y) {

	visit[y][x] = true;

	for (int i = 0; i < 8; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];

		if (tx < 0 || tx >= w || ty < 0 || ty >= h)
			continue;
		if (visit[ty][tx] || map[ty][tx] == 0)
			continue;

		dfs(tx, ty);
	}

}

int main(void) {

	while (1) {
		cin >> w >> h;

		if (w == 0 && h == 0)
			break;

		int cnt = 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++)
				cin >> map[i][j];
		}

		memset(visit, false, sizeof(visit));

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!visit[i][j] && map[i][j] == 1) {
					dfs(j, i);
					cnt++;
				}
			}
		}

		cout << cnt << endl;

	}


	return 0;
}