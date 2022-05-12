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

#define MAX 1000000001

int n;
vector<int> nums;
int op[4]; //0: + ,1: -, 2: *, 3: /
long long maxN = -MAX;
long long minN = MAX;

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		nums.push_back(x);
	}

	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}
}

void dfs(int idx, long long res, int depth) {


	if (depth == n) {
		minN = min(minN, res);
		maxN = max(maxN, res);
		return;
	}

	for (int i = idx + 1; i < n; i++) {
		int next = nums[i];

		for (int j = 0; j < 4; j++) {
			if (op[j] != 0) {
				op[j]--;
				long long temp;
				switch (j)
				{
				case 0:
					temp = res + next;
					break;
				case 1:
					temp = res - next;
					break;
				case 2:
					temp = res * next;
					break;
				case 3:
					temp = res / next;
					break;
				default:
					break;
				}
				dfs(i, temp, depth + 1);
				op[j]++;
			}
		}
	}
}

int main(void) {

	input();

	dfs(0, nums[0], 1);

	cout << maxN << endl;
	cout << minN << endl;

	return 0;
}