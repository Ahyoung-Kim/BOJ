#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>

using namespace std;

bool visit[1000000] = { false, };
int num[5][5];
int ans;

void dfs(int x, int y, string number, int depth) {

	if (depth == 6) {

		int to_num = stoi(number);

		if (!visit[to_num]) {
			visit[to_num] = true;
			ans++;
		}

		return;
	}

	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = { 1, -1, 0, 0 };

	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];

		if (tx < 0 || tx >= 5 || ty < 0 || ty >= 5)
			continue;

		string child_num = number;
		child_num.append(to_string(num[ty][tx]));
		dfs(tx, ty, child_num, depth + 1);
	}
}

int main(void) {

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			cin >> num[i][j];
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			string str = to_string(num[i][j]);
			dfs(j, i, str, 1);
		}
	}

	cout << ans;

	return 0;
}