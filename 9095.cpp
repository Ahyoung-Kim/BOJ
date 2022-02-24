#include<iostream>
#include<stack>
#include<vector>
#include<cstring>
#include<string>
#include<cstdlib>
#include<queue>
#include<algorithm>

using namespace std;

int dp[11] = { 0, };

int main(void) {

	int t, n;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	cin >> t;

	while (t > 0) {

		cin >> n;

		if (dp[n] != 0) {
			cout << dp[n] << endl;
		}
		else {
			for (int i = 4; i <= n; i++) {
				dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
			}

			cout << dp[n] << endl;
		}

		t--;
	}


	return 0;
}