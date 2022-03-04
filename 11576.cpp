#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<array>
#include<cmath>

using namespace std;

void decimal_to_b(int n, int b) {
	vector<int> ans;

	while (n > 0) {
		int temp = n % b;
		ans.push_back(temp);

		n /= b;
	}

	while (!ans.empty()) {
		cout << ans.back() << " ";
		ans.pop_back();
	}
}

int main(void) {

	int a, b, m;
	int num;

	cin >> a >> b;
	cin >> m;

	int decimal = 0;
	while (m > 0) {
		cin >> num;
		decimal += num * pow(a, m - 1);
		m--;
	}

	decimal_to_b(decimal, b);

	return 0;
}