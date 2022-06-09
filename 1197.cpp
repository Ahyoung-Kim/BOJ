#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>

using namespace std;

int v, e;
int parent[10001];
long long ans;
bool check;

typedef struct edge {
	int v1;
	int v2;
	int w;
};

struct compare {
	bool operator()(edge a, edge b) {
		return a.w > b.w;
	}
};

priority_queue < edge, vector<edge>, compare> edges;

int find(int x) {
	if (parent[x] == x)
		return x;

	return parent[x] = find(parent[x]);
}

void union_set(int x, int y) {
	check = false;

	int root_x = find(x);
	int root_y = find(y);

	if (root_x == root_y)
		return;

	parent[root_x] = root_y;
	check = true;
}


void mst() {

	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}

	while (!edges.empty()) {
		int x = edges.top().v1;
		int y = edges.top().v2;
		int w = edges.top().w;
		edges.pop();

		union_set(x, y);
		if (check) {
			ans += w;
		}
	}
}

int main(void) {

	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		edge temp = { v1, v2, w };
		edges.push(temp);
	}

	mst();
	cout << ans << endl;

	return 0;
}