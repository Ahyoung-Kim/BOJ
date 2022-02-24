#include<iostream>
#include<stack>
#include<vector>
#include<cstring>
#include<string>
#include<cstdlib>
#include<queue>
#include<algorithm>

using namespace std;

int dp[1000001] = { 0, };

int main(void) {

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	int N;

	cin >> N;

	for (int i = 4; i <= N; i++) {
		if ((i % 2 != 0) && (i % 3 != 0))
			dp[i] = dp[i - 1] + 1;
		else if ((i % 2 == 0) && (i % 3 == 0))
			dp[i] = min(dp[i / 3], dp[i / 2]) + 1;
		else if ((i % 2 == 0) && (i % 3 != 0))
			dp[i] = min(dp[i / 2], dp[i - 1]) + 1;
		else if ((i % 2 != 0) && (i % 3 == 0))
			dp[i] = min(dp[i / 3], dp[i - 1]) + 1;
	}

	cout << dp[N];

	return 0;
}