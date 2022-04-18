#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

int n, s;
int arr[21];
bool visit[21] = { false, };
int ans;

void dfs(int idx, int num) {

	if (num == s) {
		ans++;
	}

	for (int i = idx + 1; i < n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			dfs(i, num + arr[i]);
			visit[i] = false;
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		memset(visit, false, sizeof(visit));
		visit[i] = true;
		dfs(i, arr[i]);
	}

	cout << ans;

	return 0;
}