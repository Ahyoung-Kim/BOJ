#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>

using namespace std;

int main(void) {

	int T;
	char str[1001]; //���ڿ� 
	vector<char> buf; //�ܾ� ������ ����
	int j;

	cin >> T;
	cin.ignore(); //���� �����

	while (T > 0) {
		cin.getline(str, 1001); //���� �����ϴ� ���ڿ� �Է�

		for (int i = 0; i < strlen(str) + 1; i++) {

			if (str[i] == ' ' || i == strlen(str)) {
				j = i - buf.size();  //str ������ �� �ܾ��� ù ��° index

				while (!buf.empty()) {
					str[j++] = buf.back(); //�ܾ� �ٽ� ����
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