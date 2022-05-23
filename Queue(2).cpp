#include <iostream>
#include <queue>

using namespace std;

int Fibonacci(int n) {
	if (n <= 0) return 1;

	return Fibonacci(n - 2) + Fibonacci(n - 1);
}

void main(void) {

	queue<int> q;
	int n = 0;
	int pn = 0;

	cin >> n;

	if (n == 1) {
		q.push(1);
		cout << q.front();
		return;
	}

	q.push(1);
	q.push(1);

	for (int i = 1; i <= n - 2; i++) {
		q.push(Fibonacci(i));
	}

	//cout << Fibonacci(n) << endl;
	

	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
}
