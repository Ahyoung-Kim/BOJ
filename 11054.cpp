#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<cstdlib>

using namespace std;

int dp[2][1001];
int arr[1001];

int main(void) {

	int n;
	int ans1 = 0;
	int ans2 = 0;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		dp[0][i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[0][i] = max(dp[0][i], dp[0][j] + 1);
			}
		}
		ans1 = max(ans1, dp[0][i]);
	}

	for (int i = n; i >= 1; i--) {
		dp[1][i] = 1;
		for (int j = n; j > i; j--) {
			if (arr[i] > arr[j]) {
				dp[1][i] = max(dp[1][i], dp[1][j] + 1);
			}
		}
		ans2 = max(ans2, dp[0][i] + dp[1][i]);
	}

	cout << ans2 - 1;

	return 0;
}