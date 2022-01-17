#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

char word[101][101];

int is_group(char str[]) {
	int len = strlen(str);
	char prev, curr;
	char alpha[26] = { 0, };

	prev = str[0];
	int idx = prev - 97;
	alpha[idx] = 1;

	for (int i = 1; i < len; i++) {
		curr = str[i];

		if (prev == curr) {
			continue;
		}
		else {
			idx = curr - 97;
			if (alpha[idx] == 1)
				return 0;

			alpha[idx] = 1;
			prev = curr;
		}
	}
	return 1;
}

int main(void) {

	int N;
	cin >> N;
	int result = 0;

	for (int i = 0; i < N; i++) {
		cin >> word[i];
	}

	for (int i = 0; i < N; i++) {
		if (is_group(word[i]) == 1)
			result++;
	}

	cout << result << endl;

	return 0;
}