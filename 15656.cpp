#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
#include<cmath>

using namespace std;

int n, m;
int num[9];
bool visit[9] = { false, };
int arr[9];

void dfs(int idx, int depth) {

	if (depth == m - 1) {
		for (int i = 0; i < m; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");

		return;
	}

	for (int i = 0; i < n; i++) {
		arr[depth + 1] = num[i];
		dfs(i, depth + 1);
	}

}

int main(void) {

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}

	sort(num, num + n);

	for (int i = 0; i < n; i++) {
		arr[0] = num[i];
		dfs(i, 0);
	}

	return 0;
}