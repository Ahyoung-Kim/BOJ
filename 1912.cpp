#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>

using namespace std;

#define MAX 100001

int dp[MAX];
int arr[MAX];

int main(void) {

	int N;
	int ans;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	dp[0] = arr[0];
	ans = arr[0];
	for (int i = 1; i < N; i++) {
		dp[i] = max(arr[i], dp[i - 1] + arr[i]);
		ans = max(dp[i], ans);
	}

	cout << ans;

	return 0;
}