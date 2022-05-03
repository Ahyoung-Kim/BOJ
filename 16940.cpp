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

bool bfs() {

	queue<int> q;
	int seq = 2;

	visit[1] = true;
	q.push(1);

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 0; i < graph[curr].size(); i++) {
			int next = graph[curr][i];
			if (visit[next])
				continue;

			if (!visit[next] && order[next] == seq) {
				visit[next] = true;
				seq++;
				q.push(next);
			}
			else if (order[next] != seq)
				return false;
		}
	}
	return true;
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

	cout << bfs();

	return 0;
}