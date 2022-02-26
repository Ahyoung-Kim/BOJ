#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdlib>
#include<vector>

using namespace std;

typedef pair<int, int> pp;

int n;
char map[101][101];
int visit[101][101] = { 0, };

int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };

void init_visit() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = 0;
		}
	}
}

int all_visit() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == 0)
				return 0;
		}
	}
	return 1;
}

int bfs() {

	int cnt = 0;

	pp p;
	char tmp;
	int tx, ty;

	tx = ty = 0;

	while (!all_visit()) {
		queue<pp> q;

		q.push({ tx, ty });
		visit[ty][tx] = 1;
		char c = map[ty][tx];

		while (!q.empty()) {
			p = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				tx = p.first + dx[i];
				ty = p.second + dy[i];

				if (tx < 0 || tx >= n || ty < 0 || ty >= n)
					continue;
				if (visit[ty][tx] == 1)
					continue;
				if (map[ty][tx] != c)
					continue;

				visit[ty][tx] = 1;
				q.push({ tx, ty });
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visit[i][j] == 0) {
					tx = j;
					ty = i;
				}
			}
		}

		cnt++;
	}

	return cnt;
}

int main(void) {

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}

	int a = bfs();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'G')
				map[i][j] = 'R';
		}
	}
	init_visit();
	int b = bfs();

	cout << a << " " << b;

	return 0;
}