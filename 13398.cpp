#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<cstdlib>

using namespace std;

int dp[2][100001];
int arr[100001];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int ans;

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[0][1] = dp[1][1] = arr[1];
	ans = arr[1];

	for (int i = 2; i <= n; i++) {
		dp[0][i] = max(arr[i], dp[0][i - 1] + arr[i]);
		dp[1][i] = max(dp[0][i - 1], dp[1][i - 1] + arr[i]);

		ans = max(ans, max(dp[0][i], dp[1][i]));
	}

	cout << ans;

	return 0;
}