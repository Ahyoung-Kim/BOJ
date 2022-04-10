#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

typedef struct box {
	vector<vector<int>> data;
	bool visit[101][101] = { false, };
};

typedef struct node {
	int x;
	int y;
	int h;
	int depth;
};

int m, n, h; //가로, 세로, 높이
box boxs[101];
int ans;

int dx[6] = { 0, 0, 0, 0, 1, -1 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dh[6] = { 1, -1, 0, 0, 0, 0 };

bool is_complete() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (boxs[i].data[j][k] == 0)
					return false;
			}
		}
	}
	return true;
}

void bfs() {

	queue<node> q;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (boxs[i].data[j][k] == 1) {
					boxs[i].visit[j][k] = true;
					q.push({ k, j, i, 0 });
				}
			}
		}
	}

	while (!q.empty()) {
		node curr = q.front();
		q.pop();

		ans = max(ans, curr.depth);

		for (int i = 0; i < 6; i++) {
			int tx = curr.x + dx[i];
			int ty = curr.y + dy[i];
			int th = curr.h + dh[i];

			if (tx < 0 || tx >= m || ty < 0 || ty >= n
				|| th < 0 || th >= h)
				continue;
			if (boxs[th].visit[ty][tx] || boxs[th].data[ty][tx] == -1 ||
				boxs[th].data[ty][tx] == 1)
				continue;

			boxs[th].visit[ty][tx] = true;
			boxs[th].data[ty][tx] = 1;
			q.push({ tx, ty, th, curr.depth + 1 });
		}
	}

	if (!is_complete())
		ans = -1;
}

int main(void) {
	cin >> m >> n >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			vector<int> temp;
			for (int k = 0; k < m; k++) {
				int x;
				cin >> x;
				temp.push_back(x);
			}
			boxs[i].data.push_back(temp);
		}
	}

	bfs();

	cout << ans;

	return 0;
}