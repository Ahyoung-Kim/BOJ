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

			if (prev > s.size()) {  //����� ��
				result += 1;
			}
			else {  //������
				result += s.size();  //s.size(): ���� ����� �� 
			}

			prev = s.size();
		}
	}

	cout << result << endl;

	return 0;
}