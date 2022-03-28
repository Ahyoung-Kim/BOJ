#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
#include<cmath>
#include<cstdlib>
#include<cstring>

using namespace std;

bool flag = false;
int n, m;
bool visit[2000] = { false, };
vector<int> graph[2000];

void dfs(int u, int depth) {

	if (depth == 5) {
		flag = true;
		return;
	}

	for (int i = 0; i < graph[u].size(); i++) {
		int next = graph[u][i];
		if (!visit[next]) {

			visit[next] = true;
			dfs(next, depth + 1);
			if (flag) {
				return;
			}
			visit[next] = false;
		}
	}
}

int main(void) {

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 0; i < n; i++) {
		if (flag)
			break;

		memset(visit, false, sizeof(visit));
		visit[i] = true;
		dfs(i, 1);
	}

	if (flag)
		printf("1");
	else
		printf("0");

	return 0;
}