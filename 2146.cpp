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

int n;
int map[101][101];
bool visit[101][101] = { false, };
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int ans = 987654321;

typedef struct node {
	int x;
	int y;
	int len;
};

void dfs(int x, int y, int set) {
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];

		if (tx < 0 || tx >= n || ty < 0 || ty >= n)
			continue;
		if (visit[ty][tx] || map[ty][tx] == 0)
			continue;
		visit[ty][tx] = true;
		map[ty][tx] = set;
		dfs(tx, ty, set);
	}
}

void bfs(int num) {

	queue<node> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j] && map[i][j] == num) {
				visit[i][j] = true;
				q.push({ j, i , 0 });
			}
		}
	}

	while (!q.empty()) {
		node curr = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int tx = curr.x + dx[i];
			int ty = curr.y + dy[i];

			if (tx < 0 || tx >= n || ty < 0 || ty >= n)
				continue;

			if (map[ty][tx] == 0 && !visit[ty][tx]) {
				visit[ty][tx] = true;
				q.push({ tx, ty, curr.len + 1 });
			}
			else if (map[ty][tx] != 0 && map[ty][tx] != num) {
				ans = min(ans, curr.len);
				return;
			}
		}
	}
}

void solution() {

	int continent = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j] && map[i][j] == 1) {
				visit[i][j] = true;
				map[i][j] = continent;
				dfs(j, i, continent);
				continent++;
			}
		}
	}

	for (int i = 1; i < continent; i++) {
		memset(visit, false, sizeof(visit));
		bfs(i);
	}
}

int main(void) {

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	solution();

	cout << ans << endl;

	return 0;
}