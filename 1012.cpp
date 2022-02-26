#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdlib>
#include<vector>

using namespace std;

typedef pair<int, int> pp;

int m, n, k;
int map[50][50] = { 0, };
int visit[50][50] = { 0, };
int cnt;

int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };

void init() {
	cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = 0;
			visit[i][j] = 0;
		}
	}
}

void bfs(int x, int y) {

	pp p;
	queue<pp> q;

	p.first = x;
	p.second = y;

	q.push(p);
	visit[y][x] = 1;

	while (!q.empty()) {
		p = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int tx = p.first + dx[i];
			int ty = p.second + dy[i];

			if (tx < 0 || tx >= m || ty < 0 || ty >= n)
				continue;
			if (map[ty][tx] == 0)
				continue;
			if (visit[ty][tx] == 1)
				continue;

			visit[ty][tx] = 1;
			q.push({ tx, ty });
		}
	}

}

int main(void) {

	int t;
	int x, y;

	cin >> t;

	while (t > 0) {

		cin >> m >> n >> k;

		init();

		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			map[y][x] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visit[i][j] == 0 && map[i][j] == 1) {
					bfs(j, i);
					cnt++;
				}
			}
		}

		cout << cnt << endl;

		t--;
	}


	return 0;
}