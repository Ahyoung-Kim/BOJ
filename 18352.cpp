#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

#define MAX 300001

typedef struct city {
	vector<int> data;
};

typedef struct node {
	int num;
	int depth;
};

int n, m, k, x;
city cities[MAX];
bool visit[MAX];
priority_queue<int, vector<int>, greater<int>> ans;

void bfs() {
	queue<node> q;

	visit[x] = true;
	q.push({ x, 0 });

	while (!q.empty()) {
		node curr = q.front();
		q.pop();

		if (curr.depth == k) {
			ans.push(curr.num);
			continue;
		}

		for (int i = 0; i < cities[curr.num].data.size(); i++) {
			int next = cities[curr.num].data[i];

			if (visit[next])
				continue;
			visit[next] = true;
			q.push({ next, curr.depth + 1 });
		}
	}
}

int main(void) {

	cin >> n >> m >> k >> x;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		cities[u].data.push_back(v);
	}
	bfs();

	if (ans.empty()) {
		cout << -1;
		return 0;
	}

	while (!ans.empty()) {
		cout << ans.top() << endl;
		ans.pop();
	}

	return 0;
}