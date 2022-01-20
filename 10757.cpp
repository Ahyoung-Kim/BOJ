#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>

using namespace std;

int main(void) {
	string A, B, ans;
	int size_a, size_b;
	int a, b, c, s;

	cin >> A >> B;

	size_a = A.size();
	size_b = B.size();

	c = 0;

	while (size_a > 0 && size_b > 0) {

		a = A.at(--size_a) - 48;
		b = B.at(--size_b) - 48;
		s = a + b + c;

		c = s / 10;
		s = s % 10;
		s += 48;
		ans.push_back(s);
	}

	if (size_a > 0) {

		while (size_a > 0) {
			a = A.at(--size_a) - 48;
			s = a + c;

			c = s / 10;
			s = s % 10;
			s += 48;
			ans.push_back(s);
		}
	}
	else if (size_b > 0) {
		while (size_b > 0) {
			b = B.at(--size_b) - 48;
			s = b + c;

			c = s / 10;
			s = s % 10;
			s += 48;
			ans.push_back(s);
		}
	}

	if (c > 0) {
		c += 48;
		ans.push_back(c);
	}

	while (!ans.empty()) {
		cout << ans.back();
		ans.pop_back();
	}

	return 0;
}