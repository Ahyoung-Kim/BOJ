#include<iostream>
#include<stack>
#include<vector>
#include<cstring>
#include<string>
#include<cstdlib>

using namespace std;

int gcd(int a, int b) {

	if (b > a) {
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


int main(void) {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, s;
	int arr[100001];
	int dif[100001] = { 0, };
	int temp;

	cin >> n >> s;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++) {
		dif[i] = abs(s - arr[i]);
	}

	if (n == 1) {
		temp = dif[0];
	}
	else {
		for (int i = 0; i < n - 1; i++) {
			temp = gcd(dif[i], dif[i + 1]);
			dif[i + 1] = temp;
		}
	}

	cout << temp;

	return 0;
}