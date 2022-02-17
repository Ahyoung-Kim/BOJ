#include<iostream>
#include<stack>
#include<vector>
#include<cstring>
#include<string>

using namespace std;

int is_lower(char c) {
	if (c >= 'a' && c <= 'z')
		return 1;

	return 0;
}

int is_capital(char c) {
	if (c >= 'A' && c <= 'Z')
		return 1;

	return 0;
}

int is_num(char c) {
	if (c >= '0' && c <= '9')
		return 1;

	return 0;
}

int is_space(char c) {
	if (c == ' ' || c == '\t')
		return 1;

	return 0;
}


int main(void) {

	string str;
	int cap, low, num, space;

	while (getline(cin, str)) {

		cap = low = num = space = 0;

		for (int i = 0; i < str.size(); i++) {
			if (is_capital(str[i]))
				cap++;
			else if (is_lower(str[i]))
				low++;
			else if (is_num(str[i]))
				num++;
			else if (is_space(str[i]))
				space++;
		}

		printf("%d %d %d %d\n", low, cap, num, space);
	}

	return 0;
}