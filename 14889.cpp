#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<cmath>

using namespace std;

int n;
int ans = 1000000000;
int s[21][21];
int arr[21];
bool visit[21] = { false, };

int calculation(int m) {
	int sum1 = 0;
	int sum2 = 0;

	for (int i = 0; i < m; i++) {
		int x = arr[i];
		for (int j = 0; j < m; j++) {
			if (i == j)
				continue;
			int y = arr[j];
			sum1 += s[x][y];
		}
	}
	for (int i = m; i < n; i++) {
		int x = arr[i];
		for (int j = m; j < n; j++) {
			if (i == j)
				continue;
			int y = arr[j];
			sum2 += s[x][y];
		}
	}

	return abs(sum1 - sum2);
}

void dfs(int idx, int depth) {
	int m = n / 2;

	if (depth == m) {

		for (int i = 0; i < n; i++) {
			if (!visit[i])
				arr[depth++] = i;
		}

		ans = min(ans, calculation(m));

		return;
	}

	for (int i = idx + 1; i < n; i++) {
		if (!visit[i] && (n - 1 - i) >= (m - 1 - depth)) {
			visit[i] = true;
			arr[depth] = i;
			dfs(i, depth + 1);
			visit[i] = false;
		}
	}
}

int main(void) {

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> s[i][j];
	}

	arr[0] = 0;
	visit[0] = true;
	dfs(0, 1);

	cout << ans;

	return 0;
}