#include<iostream>
#include<stack>
#include<vector>
#include<cstring>
#include<string>

using namespace std;

int gcd(int a, int b) {
	int r = a % b;

	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}

	return b;
}

int main(void) {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t, n;
	int arr[101] = { 0, };
	long long ans;

	cin >> t;

	while (t > 0) {
		cin >> n;
		ans = 0;

		for (int i = 0; i < n; i++)
			cin >> arr[i];

		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				ans += gcd(arr[i], arr[j]);
			}
		}

		cout << ans << endl;

		t--;
	}

	return 0;
}