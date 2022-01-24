#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;

int factorial(int n) {
	if (n == 0 || n == 1)
		return 1;

	return n * factorial(n - 1);
}

int main(void) {
	int N;

	cin >> N;

	cout << factorial(N) << endl;

	return 0;
}