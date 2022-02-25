#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdlib>
#include<vector>

using namespace std;

typedef struct info {
	int x;
	int y;
}info;

char map[101][101];
int visit[101][101] = { 0, };
int len[101][101] = { 0, };
queue<info> q;
int n, m;

int dx[4] = { 0, 1, -1, 0 };
int dy[4] = { 1, 0, 0, -1 };

void bfs() {
	int x, y;

	info temp;

	temp.x = 0;
	temp.y = 0;

	q.push(temp);

	visit[0][0] = 1;
	len[0][0]++;

	while (!q.empty()) {
		temp = q.front();
		q.pop();

		if (temp.x == m - 1 && temp.y == n - 1) {
			return;
		}

		for (int i = 0; i < 4; i++) {
			x = temp.x + dx[i];
			y = temp.y + dy[i];

			if (x < 0 || x >= m || y < 0 || y >= n)
				continue;
			if (map[y][x] == '0')
				continue;
			if (visit[y][x] == 1)
				continue;

			visit[y][x] = 1;
			info child;
			child.x = x;
			child.y = y;
			len[y][x] = len[temp.y][temp.x] + 1;

			q.push(child);

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
	bfs();
	cout << len[n - 1][m - 1];

	return 0;
}