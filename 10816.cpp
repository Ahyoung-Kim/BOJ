#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

int main(void) {

	int n, m;

	cin >> n;
	vector<int> num(n);


	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		num[i] = x;
	}
	sort(num.begin(), num.end());

	cin >> m;
	vector<int> ans(m);

	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;

		auto low = lower_bound(num.begin(), num.end(), x);
		auto up = upper_bound(num.begin(), num.end(), x);

		ans[i] = up - low;
	}

	for (auto n : ans)
		cout << n << " ";

	return 0;
}