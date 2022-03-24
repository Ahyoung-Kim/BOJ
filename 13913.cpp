#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdio>

using namespace std;

#define MAX 100001

typedef struct node {
	int loc;
	node* parent;
}node;

int n, k;
bool generated[MAX] = { false, };
queue<node*> q;
vector<int> path;

void bfs() {

	generated[n] = true;

	node* start = new node;
	start->loc = n;
	start->parent = NULL;

	q.push(start);

	while (!q.empty()) {
		node* temp = q.front();
		q.pop();

		if (temp->loc == k) {
			node* curr = temp;

			while (curr != NULL) {
				path.push_back(curr->loc);
				curr = curr->parent;
			}

			break;
		}

		for (int i = 0; i < 3; i++) {
			int tx;
			if (i == 0)
				tx = temp->loc - 1;
			else if (i == 1)
				tx = temp->loc + 1;
			else
				tx = temp->loc * 2;

			if (tx < 0 || tx >= MAX)
				continue;
			if (generated[tx])
				continue;

			generated[tx] = true;

			node* child = new node;
			child->loc = tx;
			child->parent = temp;

			q.push(child);
		}
	}

}

int main(void) {

	cin >> n >> k;

	bfs();

	cout << path.size() - 1 << endl;

	while (!path.empty()) {
		cout << path.back() << " ";
		path.pop_back();
	}

	return 0;
}