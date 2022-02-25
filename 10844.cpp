#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdlib>
#include<vector>

#define buf 1000000000

using namespace std;

long long dp[101][10] = { 0, };

int main(void) {

	int n;
	long long ans = 0;

	cin >> n;

	for (int i = 1; i < 10; i++)
		dp[1][i]++;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][1];
			}
			else if (j == 9) {
				dp[i][j] = dp[i - 1][8];
			}
			else {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			}
			dp[i][j] %= buf;
		}
	}

	for (int i = 0; i < 10; i++) {
		ans += dp[n][i];
		ans %= buf;
	}

	cout << ans;

	return 0;
}