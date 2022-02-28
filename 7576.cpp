#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdlib>

using namespace std;

int m, n;
int map[1001][1001];
bool visit[1001][1001] = { false, };
int day = 0;

int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };

typedef struct node {
	int x, y;
	int parent_num;
}node;

queue<node> tomato;

bool all_visit() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0 && !visit[i][j])
				return false;
		}
	}
	return true;
}

void bfs() {

	node curr;

	while (!tomato.empty()) {
		curr = tomato.front();
		tomato.pop();

		for (int i = 0; i < 4; i++) {
			int tx = curr.x + dx[i];
			int ty = curr.y + dy[i];

			if (tx < 0 || tx >= m || ty < 0 || ty >= n)
				continue;
			if (visit[ty][tx] || map[ty][tx] != 0)
				continue;

			visit[ty][tx] = true;

			node child;
			child.x = tx;
			child.y = ty;
			child.parent_num = curr.parent_num + 1;

			tomato.push(child);
		}

		day = max(day, curr.parent_num);
	}

}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];

			if (map[i][j] == 1) {
				tomato.push({ j, i, 0 });
			}
		}
	}

	bfs();

	if (!all_visit())
		day = -1;

	cout << day;

	return 0;
}