#include<iostream>
#include<stack>
#include<vector>
#include<cstring>
#include<string>

using namespace std;

int main(void) {

	cin.tie(NULL);
	cout.tie(NULL);

	ios_base::sync_with_stdio(false);

	int n;
	int tmp;
	int ans = 0;

	cin >> n;

	if (n < 5) {
		ans = 0;
	}
	else {

		for (int i = 5; i <= n; i *= 5) {
			ans += n / i;
		}
	}

	cout << ans << endl;

	return 0;
}