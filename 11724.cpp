#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdlib>
#include<vector>

using namespace std;

int n, m;

int graph[1001][1001] = { 0, };
int visit[1001] = { 0, };

void dfs(int w) {

	visit[w] = 1;

	for (int i = 1; i <= n; i++) {
		if (graph[w][i] == 1 && visit[i] == 0)
			dfs(i);
	}

}

int main(void) {

	int u, v;
	int cnt = 0;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		graph[u][v] = graph[v][u] = 1;
	}

	for (int i = 1; i <= n; i++) {
		if (visit[i] == 0) {
			dfs(i);
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}