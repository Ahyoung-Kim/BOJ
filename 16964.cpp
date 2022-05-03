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

#define MAX 100001

int n;
vector<int> graph[MAX];
int order[MAX];
bool visit[MAX];
int seq = 2;
bool flag = false;

void dfs(int node) {
	if (flag)
		return;

	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (!visit[next]) {
			if (order[next] == seq) {
				visit[next] = true;
				seq++;
				dfs(next);
			}
			else {
				flag = true;
				return;
			}
		}
	}
}

bool comp(const int& a, int& b) {
	return order[a] < order[b];
}

int main(void) {

	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		order[x] = i;
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end(), comp);
	}

	visit[1] = true;
	dfs(1);

	if (flag)
		cout << 0;
	else
		cout << 1;

	return 0;
}