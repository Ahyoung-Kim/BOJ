#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>

using namespace std;

int main(void) {

	int T;
	char str[1001]; //문자열 
	vector<char> buf; //단어 저장할 스택
	int j;

	cin >> T;
	cin.ignore(); //버퍼 지우기

	while (T > 0) {
		cin.getline(str, 1001); //공백 포함하는 문자열 입력

		for (int i = 0; i < strlen(str) + 1; i++) {

			if (str[i] == ' ' || i == strlen(str)) {
				j = i - buf.size();  //str 내에서 각 단어의 첫 번째 index

				while (!buf.empty()) {
					str[j++] = buf.back(); //단어 다시 저장
					buf.pop_back();
				}
			}
			else {
				buf.push_back(str[i]);
			}
		}

		cout << str << endl;
		T--;
	}

	return 0;
}