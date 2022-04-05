#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>

using namespace std;

int n;
int arr[13];
int dfs_arr[6];
bool visit[13] = { false, };

void dfs(int idx, int depth) {

	if (depth == 6) {
		for (int i = 0; i < 6; i++)
			cout << dfs_arr[i] << " ";
		cout << endl;
		return;
	}

	for (int i = idx + 1; i < n; i++) {
		if (!visit[i] && (n - i - 1) >= (5 - depth)) {
			visit[i] = true;
			dfs_arr[depth] = arr[i];
			dfs(i, depth + 1);
			visit[i] = false;
		}
	}

}

int main(void) {

	while (true) {
		cin >> n;

		if (n == 0)
			break;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		for (int i = 0; i < n; i++) {
			memset(visit, false, sizeof(visit));
			dfs_arr[0] = arr[i];
			visit[i] = true;
			dfs(i, 1);
			visit[i] = false;
		}

		cout << endl;
	}

	return 0;
}