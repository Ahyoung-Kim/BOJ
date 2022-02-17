#include<iostream>
#include<stack>
#include<vector>
#include<cstring>

using namespace std;

int N;
char post[101];
double arr[26]; //A: 0 ~ Z: 25
stack<double> s;
double result;
double tmp1, tmp2;
int temp;


int main(void) {

	cin >> N;

	cin >> post;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < strlen(post); i++) {

		if (post[i] >= 'A' && post[i] <= 'Z') {
			temp = post[i] - 65;
			tmp1 = arr[temp];
			s.push(tmp1);
		}
		else {
			tmp1 = s.top();
			s.pop();
			tmp2 = s.top();
			s.pop();

			if (post[i] == '*') {
				result = (double)(tmp1 * tmp2);
			}
			else if (post[i] == '+') {
				result = (double)(tmp1 + tmp2);
			}
			else if (post[i] == '-') {
				result = (double)(tmp2 - tmp1);
			}
			else if (post[i] == '/') {
				result = (double)(tmp2 / tmp1);
			}
			s.push(result);
		}

	}

	cout << fixed;
	cout.precision(2);
	cout << s.top() << endl;

	return 0;
}