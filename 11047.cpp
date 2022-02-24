#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int main(void) {

	int n, k;
	int value[11];
	int ans = 0;

	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> value[i];

	for (int i = n - 1; i >= 0; i--) {
		if (k == 0)
			break;

		if (k < value[i])
			continue;

		ans += (k / value[i]);
		k %= value[i];
	}

	cout << ans;

	return 0;
}