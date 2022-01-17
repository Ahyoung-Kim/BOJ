#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

int main(void) {
	int N, temp, i;
	int row = 1, col = 1;
	int group = 1;
	int first = 1;

	cin >> N;
	temp = N;
	N--;

	while (N > 0) {
		group++;
		N -= group;
	}

	for (i = 1; i <= group - 1; i++)
		first += i;

	int d = temp - first;

	if (group % 2 == 0) {
		col = group;

		for (i = 0; i < d; i++) {
			row++;
			col--;
		}
	}
	else {
		row = group;
		for (i = 0; i < d; i++) {
			row--;
			col++;
		}
	}

	printf("%d/%d\n", row, col);

	return 0;
}