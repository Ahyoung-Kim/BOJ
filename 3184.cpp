#include<iostream>
#include<cstdlib>
#include<vector>
#include<queue>

using namespace std;

int r, c;
int v, o;
int tv, to;
char map[250][250];
bool visit[250][250] = { false, };

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(int x, int y) {

	visit[y][x] = true;

	if (map[y][x] == 'o')
		to++;
	else if (map[y][x] == 'v')
		tv++;

	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];

		if (tx < 0 || tx >= c || ty < 0 || ty >= r)
			continue;
		if (visit[ty][tx] || map[ty][tx] == '#')
			continue;

		dfs(tx, ty);
	}
}

int main(void) {

	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];

			if (map[i][j] == 'o') {
				o++;
			}
			else if (map[i][j] == 'v') {
				v++;
			}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (!visit[i][j] && (map[i][j] == 'v' || map[i][j] == 'o')) {
				tv = to = 0;
				dfs(j, i);

				if (tv >= to) {
					o -= to;
				}
				else {
					v -= tv;
				}
			}
		}
	}

	cout << o << " " << v;

	return 0;
}