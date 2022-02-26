#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdlib>
#include<vector>

using namespace std;

int n;
int e;
int visit[101] = { 0, };
int ans = 0;
int g[101][101];

void bfs() {

	queue<int> open_list;

	open_list.push(1);
	visit[1] = 1;

	while (!open_list.empty()) {
		int temp = open_list.front();
		open_list.pop();
		ans++;

		for (int i = 1; i <= n; i++) {
			if (g[temp][i] == 1 && visit[i] == 0) {
				visit[i] = 1;
				open_list.push(i);
			}
		}
	}

}

int main(void) {

	int u, v;

	cin >> n >> e;

	for (int i = 1; i <= e; i++) {
		cin >> u >> v;
		g[u][v] = g[v][u] = 1;

	}

	bfs();
	cout << ans - 1;

	return 0;
}