#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdlib>
#include<vector>

using namespace std;

typedef pair<int, int> pp;

int n;
priority_queue<int, vector<int>, greater<int>> ans;
char map[25][25];
int visit[25][25] = { 0, };
int cnt = 0;

int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };

int bfs(int y, int x) {

	int tx, ty;
	queue<pp> q;
	pp temp;

	q.push({ y, x });
	visit[y][x] = 1;

	while (!q.empty()) {
		temp = q.front();
		q.pop();
		cnt++;

		for (int i = 0; i < 4; i++) {
			ty = temp.first + dy[i];
			tx = temp.second + dx[i];

			if (tx < 0 || tx >= n || ty < 0 || ty >= n)
				continue;
			if (map[ty][tx] == '0')
				continue;
			if (visit[ty][tx] == 1)
				continue;

			visit[ty][tx] = 1;
			q.push({ ty, tx });
		}
	}

	return cnt;
}

int main(void) {

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == '1' && visit[i][j] == 0) {
				cnt = 0;
				int ret = bfs(i, j);
				ans.push(ret);
			}
		}
	}

	cout << ans.size() << endl;

	while (!ans.empty()) {
		cout << ans.top() << endl;
		ans.pop();
	}

	return 0;
}