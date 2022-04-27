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
int ans;
int map[15][15];

bool is_digonal(int px, int py, int cx, int cy) {
	int dx = abs(px - cx);
	int dy = abs(py - cy);

	if (dx == dy)
		return true;
	else
		return false;
}

void set_attack(int x, int y, int col, int set) {

	for (int i = 1; i <= n; i++) {
		for (int j = x; j <= n; j++) {
			if (i == y || j == x || is_digonal(x, y, j, i)) {
				if (map[i][j] == col)
					map[i][j] = set;
			}
		}
	}
}

void dfs(int col) {

	if (col == n + 1) {
		ans++;
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (map[i][col] == 0) {
			set_attack(col, i, 0, col);
			map[i][col] = -1;
			dfs(col + 1);
			set_attack(col, i, col, 0);
			map[i][col] = 0;
		}
	}
}

int main(void) {

	cin >> n;

	dfs(1);
	cout << ans;

	return 0;
}