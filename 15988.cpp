#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdlib>
#include<vector>

using namespace std;

#define buf 1000000009

long long dp[10000001] = { 0, };

int main(void) {

	int t, n;

	cin >> t;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	while (t > 0) {

		cin >> n;

		if (dp[n] == 0) {
			for (int i = 4; i <= n; i++) {
				if (dp[n] != 0)
					continue;

				dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % buf;
			}
		}

		cout << dp[n] % buf << endl;

		t--;
	}

	return 0;
}