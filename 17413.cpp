#include<iostream>
#include<cstring>
#include<vector>

using namespace std;


int main(void) {

	char str[100001]; //문자열 
	vector<char> buf; //단어 저장할 스택
	int j;
	int flag = 0;

	cin.getline(str, 100001); //공백 포함하는 문자열 입력

	for (int i = 0; i < strlen(str) + 1; i++) {
		if (flag == 1) {
			if (str[i] == '>')
				flag = 0;
			continue;
		}

		if (str[i] == ' ' || str[i] == '<' || i == strlen(str)) {
			j = i - buf.size();  //str 내에서 각 단어의 첫 번째 index

			while (!buf.empty()) {
				str[j++] = buf.back(); //단어 다시 저장
				buf.pop_back();
			}

			if (str[i] == '<')
				flag = 1;
		}
		else {
			buf.push_back(str[i]);
		}

	}

	cout << str << endl;

	return 0;
}