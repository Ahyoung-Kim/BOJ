#include<iostream>
#include<cstring>
#include<vector>

using namespace std;


int main(void) {

	char str[100001]; //���ڿ� 
	vector<char> buf; //�ܾ� ������ ����
	int j;
	int flag = 0;

	cin.getline(str, 100001); //���� �����ϴ� ���ڿ� �Է�

	for (int i = 0; i < strlen(str) + 1; i++) {
		if (flag == 1) {
			if (str[i] == '>')
				flag = 0;
			continue;
		}

		if (str[i] == ' ' || str[i] == '<' || i == strlen(str)) {
			j = i - buf.size();  //str ������ �� �ܾ��� ù ��° index

			while (!buf.empty()) {
				str[j++] = buf.back(); //�ܾ� �ٽ� ����
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