#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

int main(void) {
	int A, B, V;
	int n = 0;

	cin >> A >> B >> V;

	n = (V - B - 1) / (A - B) + 1;

	cout << n << endl;

	return 0;
}