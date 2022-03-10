#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

int dp[1001][3];
int rgb[1001][3];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int minsum;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
	}

	for (int i = 0; i < 3; i++) {
		dp[1][i] = rgb[1][i];
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				minsum = min(dp[i - 1][1], dp[i - 1][2]);
			}
			else if (j == 1) {
				minsum = min(dp[i - 1][0], dp[i - 1][2]);
			}
			else {
				minsum = min(dp[i - 1][1], dp[i - 1][0]);
			}
			dp[i][j] = rgb[i][j] + minsum;
		}
	}

	minsum = dp[n][0];
	for (int i = 1; i < 3; i++) {
		minsum = min(minsum, dp[n][i]);
	}

	cout << minsum;

	return 0;
}