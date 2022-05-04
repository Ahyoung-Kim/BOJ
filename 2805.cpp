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

int n, m;
vector<int> tree;
int ans;

int main(void) {

	int s = 0;
	int e = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		tree.push_back(x);

		if (e < x)
			e = x;
	}

	while (s <= e) {
		int mid = (s + e) / 2;
		long long sum = 0;

		for (int i = 0; i < n; i++) {
			if (tree[i] > mid)
				sum += (tree[i] - mid);
		}

		if (sum == m) {
			ans = mid;
			break;
		}
		else if (sum > m) {
			ans = max(ans, mid);
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}

	cout << ans;

	return 0;
}