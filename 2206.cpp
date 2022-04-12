#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

#define MAX 1001

typedef struct node {
	int x;
	int y;
	int depth;
	int flag;
};

int n, m;
int map[MAX][MAX];
bool visit[MAX][MAX][2] = { false, };

int bfs() {

	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = { 1, -1, 0, 0 };

	queue<node> q;

	visit[0][0][0] = true;
	q.push({ 0, 0, 1, false });

	while (!q.empty()) {
		node curr = q.front();
		q.pop();


		if (curr.x == m - 1 && curr.y == n - 1) {
			return curr.depth;
		}

		for (int i = 0; i < 4; i++) {
			int tx = curr.x + dx[i];
			int ty = curr.y + dy[i];

			if (tx < 0 || tx >= m || ty < 0 || ty >= n)
				continue;

			if (map[ty][tx] == 1 && curr.flag == 0) {
				visit[ty][tx][curr.flag + 1] = true;
				q.push({ tx, ty, curr.depth + 1, curr.flag + 1 });
			}
			else if (map[ty][tx] == 0 && !visit[ty][tx][curr.flag]) {
				visit[ty][tx][curr.flag] = true;
				q.push({ tx, ty, curr.depth + 1, curr.flag });
			}
		}

	}
	return -1;
}

int main(void) {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++) {
			map[i][j] = temp[j] - 48;
		}
	}

	cout << bfs();

	return 0;
}