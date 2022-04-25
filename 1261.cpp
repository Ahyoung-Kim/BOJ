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

#define MAX 101

int n, m;
bool visit[MAX][MAX][MAX * MAX] = { false, };
int map[MAX][MAX];

typedef struct node {
	int x;
	int y;
	int cnt;
};

struct compare {
	bool operator()(node a, node b) {
		return a.cnt > b.cnt;
	}
};

int bfs() {

	priority_queue < node, vector<node>, compare > q;

	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = { 1, -1, 0, 0 };

	visit[0][0][0] = true;
	q.push({ 0, 0, 0 });

	while (!q.empty()) {
		node curr = q.top();
		q.pop();

		if (curr.x == m - 1 && curr.y == n - 1) {
			return curr.cnt;
		}

		for (int i = 0; i < 4; i++) {
			int tx = dx[i] + curr.x;
			int ty = dy[i] + curr.y;

			if (tx < 0 || tx >= m || ty < 0 || ty >= n)
				continue;

			if (map[ty][tx] == 0 && !visit[ty][tx][curr.cnt]) {
				visit[ty][tx][curr.cnt] = true;
				q.push({ tx, ty, curr.cnt });
			}
			else if (map[ty][tx] == 1 && !visit[ty][tx][curr.cnt + 1]) {
				visit[ty][tx][curr.cnt + 1] = true;
				q.push({ tx, ty, curr.cnt + 1 });
			}
		}
	}

}

int main(void) {

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		string num;
		cin >> num;
		for (int j = 0; j < m; j++) {
			map[i][j] = num[j] - 48;
		}
	}

	cout << bfs();

	return 0;
}