#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

#define N 101

char word[N];

int main(void) {

	cin >> word;
	int len = strlen(word);
	int words = 0;

	for (int i = 0; i < len; i++) {
		char c = word[i];

		if (c == 'c') {
			if (word[i + 1] == '=' || word[i + 1] == '-') {
				i++;
			}
			words++;
		}
		else if (c == 'd') {
			if (word[i + 1] == 'z' && word[i + 2] == '=')
				i += 2;
			else if (word[i + 1] == '-')
				i++;
			words++;
		}
		else if (c == 'l' || c == 'n') {
			if (word[i + 1] == 'j')
				i++;
			words++;
		}
		else if (c == 's' || c == 'z') {
			if (word[i + 1] == '=')
				i++;
			words++;
		}
		else
			words++;
	}

	cout << words << endl;

	return 0;
}