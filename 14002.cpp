#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<array>
#include<cmath>

using namespace std;

typedef struct info {
	int n;
	vector<int> seq;
};

vector<info> dp(1001, { 1, });
int arr[1001];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ans = 0, idx = 0;
	int n, maxidx;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (dp[i].n < dp[j].n + 1) {
					dp[i].n = dp[j].n + 1;
					maxidx = j;
				}
			}
		}

		if (dp[i].n <= 1) {
			dp[i].seq.push_back(arr[i]);
		}
		else {
			dp[i].seq = dp[maxidx].seq;
			dp[i].seq.push_back(arr[i]);
		}

		if (ans < dp[i].n) {
			ans = dp[i].n;
			idx = i;
		}
	}

	cout << ans << endl;

	for (int i = 0; i < dp[idx].seq.size(); i++)
		cout << dp[idx].seq[i] << " ";

	return 0;
}