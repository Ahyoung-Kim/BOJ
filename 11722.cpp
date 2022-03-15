#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<cstdlib>

using namespace std;

vector<int> dp(1001, 1);
int arr[1001];

int main(void) {

	int n;
	int ans = 0;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[i] < arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}

	cout << ans;

	return 0;
}