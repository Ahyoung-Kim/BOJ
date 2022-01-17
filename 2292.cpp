#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

int main(void) {
	int N;
	int i = 1;

	cin >> N;

	N--;

	while (N > 0) {
		int temp = 6 * i;

		N -= temp;
		i++;
	}

	cout << i << endl;

	return 0;
}