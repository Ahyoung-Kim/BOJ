#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

#define mod 10007

long long dp[10][1001];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	long long ans = 0;

	cin >> n;

	for (int i = 0; i <= 9; i++) {
		dp[i][1] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = j; k <= 9; k++) {
				dp[j][i] += dp[k][i - 1];
			}
			dp[j][i] %= mod;
		}
	}

	for (int i = 0; i <= 9; i++) {
		ans += dp[i][n];
	}

	cout << ans % mod;

	return 0;
}