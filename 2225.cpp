#include<iostream>
#include <string>
#include <vector>
#include<queue>

using namespace std;

#define mod 1000000000
long long dp[201][201] = { 0, };

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;

	cin >> n >> k;

	for (int i = 0; i <= n; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			for (int s = 0; s <= j; s++) {
				dp[i][j] += dp[i - 1][s];
			}
			dp[i][j] %= mod;
		}
	}

	cout << dp[k][n];

	return 0;
}