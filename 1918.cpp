#include<iostream>
#include<stack>
#include<vector>
#include<cstring>

using namespace std;

stack<char> s;
char str[101];

int main(void) {

	int i;
	char c;

	cin >> str;

	for (i = 0; i < strlen(str); i++) {
		c = str[i];

		if (c >= 'A' && c <= 'Z') {
			cout << c;
		}
		else {
			if (c == ')') {
				while (s.top() != '(') {
					cout << s.top();
					s.pop();
				}
				s.pop();
			}
			else if (c == '(') {
				s.push(c);
			}
			else if (c == '*' || c == '/') {
				while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
					cout << s.top();
					s.pop();
				}
				s.push(c);
			}
			else if (c == '+' || c == '-') {
				while (!s.empty() && s.top() != '(') {
					cout << s.top();
					s.pop();
				}
				s.push(c);
			}

		}
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}

	return 0;
}