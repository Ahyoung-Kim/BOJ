#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

typedef pair<int, int> tp;

int n;
vector<tp> arr;
int ans;

void solution(int idx, int sum) {

	int next = idx + arr[idx].first;

	if (idx == n - 1 || next >= n) {
		ans = max(ans, sum);
		return;
	}
	else {
		for (int i = next; i < n; i++) {
			if (i + arr[i].first <= n)
				solution(i, sum + arr[i].second);
		}
	}

	ans = max(ans, sum);
}

int main(void) {

	cin >> n;

	for (int i = 0; i < n; i++) {
		int t, p;

		cin >> t >> p;

		arr.push_back({ t, p });
	}

	for (int i = 0; i < n; i++) {
		if (i + arr[i].first > n)
			continue;

		solution(i, arr[i].second);
	}

	cout << ans;

	return 0;
}