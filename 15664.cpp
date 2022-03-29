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
vector<bool> num_child[9];

void dfs(int idx, int depth) {

	if (depth == m - 1) {

		for (int i = 0; i < m; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	int check = 0;

	for (int i = idx + 1; i < n; i++) {
		if (!visit[i] && check != num[i]) {
			visit[i] = true;
			arr[depth + 1] = num[i];
			check = num[i];
			dfs(i, depth + 1);
			visit[i] = false;
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

		memset(visit, false, sizeof(visit));
		visit[i] = true;
		check = num[i];
		arr[0] = num[i];
		dfs(i, 0);
		visit[i] = false;
	}

	return 0;
}