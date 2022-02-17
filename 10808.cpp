#include<iostream>
#include<stack>
#include<vector>
#include<cstring>

using namespace std;

int alpha[26];
char str[101];

int main(void) {

	int temp;

	cin >> str;

	for (int i = 0; i < strlen(str); i++) {
		temp = str[i];
		temp -= 97;

		alpha[temp]++;
	}

	for (int i = 0; i < 26; i++)
		cout << alpha[i] << " ";


	return 0;
}