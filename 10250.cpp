#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

int main(void) {
	int T, H, W, N;
	int room;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> H >> W >> N;

		if (N % H == 0) {
			room = H * 100;
			room += (N / H);
		}
		else {
			room = (N % H) * 100 + (N / H) + 1;
		}
		cout << room << endl;
	}

	return 0;
}