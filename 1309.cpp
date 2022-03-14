#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

#define mod 9901
long long dp[1000001][3] = { 0, };

int main(void) {

	int N;

	cin >> N;

	for (int i = 0; i < 3; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= N; i++) {

		dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
		dp[i][1] = dp[i - 1][0] + dp[i - 1][2];
		dp[i][2] = dp[i - 1][0] + dp[i - 1][1];

		for (int j = 0; j < 3; j++)
			dp[i][j] %= mod;
	}

	long long ans = 0;
	for (int i = 0; i < 3; i++)
		ans += dp[N][i];

	cout << ans % mod;

	return 0;
}