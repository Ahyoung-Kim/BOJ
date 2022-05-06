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

int n, m;
vector<int> arr;
vector<int> ans;

int binary_search(int s, int e, int x) {

	if (s > e)
		return 0;

	if (s == e)
		return (arr[s] == x) ? 1 : 0;

	int mid = (s + e) / 2;

	if (arr[mid] == x)
		return 1;
	else if (arr[mid] > x)
		return binary_search(s, mid - 1, x);
	else
		return binary_search(mid + 1, e, x);
}

int main(void) {

	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end());

	cin >> m;

	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		int ret = binary_search(0, n - 1, x);
		ans.push_back(ret);
	}

	for (int i = 0; i < m; i++)
		cout << ans[i] << " ";


	return 0;
}