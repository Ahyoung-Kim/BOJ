#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdlib>

using namespace std;

int dp[1001] = { 0, };
int p[10001];

int main(void) {

	int n;

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> p[i];

	dp[1] = p[1];

	for (int i = 2; i <= n; i++) {
		int minnum = p[i];
		for (int j = i - 1; j >= i / 2; j--) {
			minnum = min(minnum, dp[i - j] + dp[j]);
		}
		dp[i] = minnum;
	}

	cout << dp[n];

	return 0;
}