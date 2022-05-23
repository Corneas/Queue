#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	string str[3];
	stack<string> s;

	cin >> str[0] >> str[1] >> str[2];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < str[i].length(); i++) {
			s.push(str[i].at(j));
		}
	}
}