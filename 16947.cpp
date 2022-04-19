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

int n;
vector<int> graph[3001];
int circle[3001] = { 1, };
bool visit[3001] = { false, };
bool findCircle = false;

typedef struct node {
	int num;
	int depth;
	node* parent;
};

void bfs(int start) {

	if (graph[start].size() < 2)
		return;

	queue<node*> q;
	bool flag = false;

	visit[start] = true;
	node* start_node = new node;
	start_node->num = start;
	start_node->depth = 1;
	start_node->parent = NULL;
	q.push(start_node);

	while (!q.empty()) {
		node* curr = q.front();
		q.pop();

		flag = false;

		for (int i = 0; i < graph[curr->num].size(); i++) {
			int next = graph[curr->num][i];

			if (!visit[next]) {
				visit[next] = true;
				node* child = new node;
				child->num = next;
				child->depth = curr->depth + 1;
				child->parent = curr;
				q.push(child);
			}
			else {
				if (next == start && curr->depth >= 3) {
					flag = true;
				}
				else if (next != start && next != curr->parent->num) {
					node* child = new node;
					child->num = next;
					child->depth = curr->depth + 1;
					child->parent = curr;
					q.push(child);
				}
			}
		}

		if (flag && curr->depth >= 3) {

			memset(circle, 1, sizeof(circle));
			node* tmp = curr;
			while (tmp != NULL) {
				if (circle[tmp->num] == 0)
					return;

				circle[tmp->num] = 0;
				tmp = tmp->parent;
			}
			findCircle = true;
			return;
		}
	}
}

void dfs(int num, int depth) {
	for (int i = 0; i < graph[num].size(); i++) {
		int child = graph[num][i];
		if (circle[child] != 0 && !visit[child]) {
			visit[child] = true;
			circle[child] = depth + 1;
			dfs(child, depth + 1);
		}
	}
}

void find_circle() {
	for (int i = 1; i <= n; i++) {
		memset(visit, false, sizeof(visit));
		bfs(i);

		if (findCircle) {
			memset(visit, false, sizeof(visit));
			for (int j = 1; j <= n; j++) {
				if (circle[j] == 0) {
					dfs(j, 0);
				}
			}
			return;
		}
	}
}

int main(void) {

	cin >> n;

	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	find_circle();

	for (int i = 1; i <= n; i++) {
		cout << circle[i] << " ";
	}
	cout << endl;

	return 0;
}