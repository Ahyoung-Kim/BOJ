#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<array>
#include<cmath>

using namespace std;

vector<int> dp(1001, 1);
int arr[1001];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ans = 0;
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}

	cout << ans;

	return 0;
}