#include<iostream>
#include<queue>

using namespace std;

int g[101][101];
bool visit[101] = { false, };
int n, m;
int u, v;

typedef pair<int, int> node;

int bfs() {

	if (g[u][v] == 1)
		return 1;

	queue<node> q;

	visit[u] = 1;
	q.push({ u, 0 });

	while (!q.empty()) {
		node temp = q.front();
		q.pop();

		if (temp.first == v) {
			return temp.second;
		}

		for (int i = 1; i <= n; i++) {
			if (g[temp.first][i] && !visit[i]) {
				q.push({ i, temp.second + 1 });
				visit[i] = true;
			}
		}
	}

	return -1;
}

int main(void) {

	cin >> n;
	cin >> u >> v;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int p, c;

		cin >> p >> c;

		g[p][c] = g[c][p] = 1;
	}

	int ret = bfs();

	cout << ret;

	return 0;
}