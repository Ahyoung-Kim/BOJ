#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<cstdlib>
#include<algorithm>

using namespace std;

int n;
char map[51][51];

void swap(char& a, char& b) {
	char temp;

	temp = a;
	a = b;
	b = temp;
}

int length(int x, int y) {
	int xans = 0, yans = 0;
	int len = 1;
	char xc, yc;

	xc = map[y][0];
	for (int i = 1; i < n; i++) {
		if (xc == map[y][i]) {
			len++;
		}
		else {
			xc = map[y][i];
			len = 1;
		}
		xans = max(xans, len);
	}
	len = 1;
	yc = map[0][x];
	for (int i = 1; i < n; i++) {
		if (yc == map[i][x]) {
			len++;
		}
		else {
			yc = map[i][x];
			len = 1;
		}
		yans = max(yans, len);
	}

	return max(xans, yans);
}

int main(void) {

	int ans = 0;

	cin >> n;

	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = { 1, -1, 0, 0 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans = max(ans, length(j, i));
			for (int k = 0; k < 4; k++) {
				int tx = j + dx[k];
				int ty = i + dy[k];

				if (tx < 0 || tx >= n || ty < 0 || ty >= n)
					continue;
				if (map[i][j] == map[ty][tx])
					continue;

				swap(map[i][j], map[ty][tx]);
				int ret = length(j, i);
				ans = max(ans, ret);
				swap(map[i][j], map[ty][tx]);
			}

			if (ans == n) {
				cout << ans;
				return 0;
			}
		}
	}

	cout << ans;

	return 0;
}