#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<array>

using namespace std;

#define MAX 100001

int n, k;
bool visit[MAX] = { false, };
typedef pair<int, int> node;

int bfs() {
	queue<node> q;

	q.push({ n, 0 });
	visit[n] = true;

	while (!q.empty()) {
		node curr = q.front();
		q.pop();

		if (curr.first == k) {
			return curr.second;
		}

		int temp = curr.first;
		if (temp - 1 >= 0 && !visit[temp - 1]) {
			visit[temp - 1] = true;
			q.push({ temp - 1, curr.second + 1 });
		}
		if (temp + 1 < MAX && !visit[temp + 1]) {
			visit[temp + 1] = true;
			q.push({ temp + 1, curr.second + 1 });
		}
		if (temp > 0 && temp * 2 < MAX && !visit[temp * 2]) {
			visit[temp * 2] = true;
			q.push({ temp * 2, curr.second + 1 });
		}

	}

}


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	int ret = bfs();

	cout << ret;

	return 0;
}