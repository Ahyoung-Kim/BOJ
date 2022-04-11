#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

#define MAX 20001

vector<int> graph[MAX];
int color[MAX];
int V, E;

void dfs(int num, int clr) {
	color[num] = clr;

	for (int i = 0; i < graph[num].size(); i++) {
		int next = graph[num][i];
		if (!color[next])
			dfs(next, 3 - clr);
	}
}

bool solution() {
	for (int i = 1; i <= V; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			int next = graph[i][j];
			if (color[i] == color[next])
				return false;
		}
	}
	return true;
}


int main(void) {

	int k;

	cin >> k;

	while (k > 0) {

		cin >> V >> E;

		memset(color, 0, sizeof(color));

		for (int i = 1; i < MAX; i++)
			graph[i].clear();

		for (int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		for (int i = 1; i <= V; i++) {
			if (color[i] == 0)
				dfs(i, 1);
		}

		bool ret = solution();

		if (ret)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

		k--;
	}

	return 0;
}