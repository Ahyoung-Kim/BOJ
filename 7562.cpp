#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };

typedef pair<int, int> coord;

typedef struct node {
	coord loc;
	int depth;
};

coord s, e;
int t, n;
bool visit[301][301] = { false, };

int bfs() {
	queue<node> q;

	q.push({ s, 0 });
	visit[s.second][s.first] = true;

	while (!q.empty()) {
		node curr = q.front();
		q.pop();

		if (curr.loc == e) {
			return curr.depth;
		}

		for (int i = 0; i < 8; i++) {
			int tx = curr.loc.first + dx[i];
			int ty = curr.loc.second + dy[i];

			if (tx < 0 || tx >= n || ty < 0 || ty >= n)
				continue;
			if (visit[ty][tx])
				continue;
			visit[ty][tx] = true;
			q.push({ {tx, ty}, curr.depth + 1 });
		}
	}

}

int main(void) {

	cin >> t;

	while (t > 0) {
		cin >> n;

		int x, y;
		cin >> x >> y;
		s.first = x;
		s.second = y;
		cin >> x >> y;
		e.first = x;
		e.second = y;

		memset(visit, false, sizeof(visit));

		int ret = bfs();
		cout << ret << endl;

		t--;
	}


	return 0;
}