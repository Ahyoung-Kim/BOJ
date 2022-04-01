#include<iostream>
#include<algorithm>
#include<array>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>

using namespace std;

#define MAX 100000000;

int n;
int w[11][11];
int ans = MAX;
bool visit[11] = { false, };

void dfs(int start, int prev, int sum, int depth) {
	if (depth == n && w[prev][start] != 0) {
		sum += w[prev][start];
		ans = min(ans, sum);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visit[i] && w[prev][i] != 0) {
			visit[i] = true;
			dfs(start, i, sum + w[prev][i], depth + 1);
			visit[i] = false;
		}
	}
}

int main(void) {

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> w[i][j];
	}

	for (int i = 0; i < n; i++) {
		memset(visit, false, sizeof(visit));
		visit[i] = true;
		dfs(i, i, 0, 1);
	}

	cout << ans;

	return 0;
}