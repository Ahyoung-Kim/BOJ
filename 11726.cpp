#include<iostream>
#include<stack>
#include<vector>
#include<cstring>
#include<string>
#include<cstdlib>
#include<queue>
#include<algorithm>

using namespace std;

int dp[1001] = { 0, };

int main(void) {

	int n;

	cin >> n;

	dp[1] = 1;
	dp[2] = 2;

	//bottom_up
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	cout << dp[n];

	return 0;
}