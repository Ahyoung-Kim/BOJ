#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
#include<cmath>
#include<cstdlib>
#include<cstring>

using namespace std;

int n, m;
int num[9];
int arr[9];
bool visit[9] = { false, };

void dfs(int idx, int depth) {

	if (depth == m - 1) {

		for (int i = 0; i < m; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	int check = 0;

	for (int i = 0; i < n; i++) {
		if (check != num[i]) {
			arr[depth + 1] = num[i];
			check = num[i];
			dfs(i, depth + 1);
		}
	}

}

int main(void) {

	int check = 0;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}

	sort(num, num + n);

	for (int i = 0; i < n; i++) {

		if (check == num[i])
			continue;

		check = num[i];
		arr[0] = num[i];
		dfs(i, 0);
	}

	return 0;
}