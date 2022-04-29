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
int tree[50][50];
int dnode;
int leaf;

void dfs(int node) {

	if (node == dnode)
		return;

	bool flag = false;

	for (int i = 0; i < n; i++) {
		if (i != dnode && tree[node][i] == 1) {
			if (!flag)
				flag = true;

			dfs(i);
		}
	}

	if (!flag)
		leaf++;
}

int main(void) {

	int root = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int parent;
		cin >> parent;

		if (parent == -1) {
			root = i;
			continue;
		}

		tree[parent][i] = 1;
	}

	cin >> dnode;

	dfs(root);

	cout << leaf;

	return 0;
}