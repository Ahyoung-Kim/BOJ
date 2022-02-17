#include<iostream>
#include<cstring>
#include<vector>
#include<stack>

using namespace std;


int main(void) {

	char str[100001];
	stack<char> s;
	int result = 0;
	int prev = 0;

	cin >> str;

	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '(') {
			s.push(str[i]);
		}
		else if (str[i] == ')') {
			s.pop();

			if (prev > s.size()) {  //막대기 끝
				result += 1;
			}
			else {  //레이저
				result += s.size();  //s.size(): 남은 막대기 수 
			}

			prev = s.size();
		}
	}

	cout << result << endl;

	return 0;
}