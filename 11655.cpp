#include<iostream>
#include<stack>
#include<vector>
#include<cstring>
#include<string>

using namespace std;

int main(void) {

	string str;

	getline(cin, str);

	for (int i = 0; i < str.size(); i++) {
		char c = str[i];

		if (c >= 'A' && c <= 'Z') {
			c += 13;

			if (c > 90) {
				char temp = c - 90;
				c = 64;

				while (temp > 0) {
					c++;
					temp--;
				}
			}

			str[i] = c;
		}
		else if (c >= 'a' && c <= 'z') {

			if ((c + 13) > 122) {
				char temp = c - 109;
				c = 96;

				while (temp > 0) {
					c++;
					temp--;
				}
			}
			else
				c += 13;

			str[i] = c;
		}
	}

	cout << str << endl;

	return 0;
}