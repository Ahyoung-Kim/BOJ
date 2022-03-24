#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdio>

using namespace std;

int gcd(int a, int b) {

	if (a < b) {
		int temp = a;
		a = b;
		b = temp;
	}

	int r = a % b;

	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}

	return b;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main(void) {
	int t;
	int n, m, x, y;

	cin >> t;

	while (t > 0) {

		cin >> m >> n >> x >> y;

		int i;
		bool flag = false;
		int limit = lcm(m, n);

		for (i = x; i <= limit; i += m) {
			if ((i - 1) % n + 1 == y) {
				flag = true;
				break;
			}
		}

		if (flag) {
			cout << i << endl;
		}
		else {
			cout << -1 << endl;
		}

		t--;
	}
}