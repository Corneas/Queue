#include <iostream>
#include <vector>
#include <array>

using namespace std;

vector<int> v;

void InitQueue(int qsize) {
	for (int i = 0; i < qsize; i++) {
		v.push_back(i);
	}
}

void Enqueue(int data) {



}

int Dequeue() {

	int vCount = 1;

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == i) {
			vCount++;
		}
	}

	if (vCount == v.size()) {
		v.pop_back();
		return 1;
	}
	
}

int IsFull(int qsize) {

	int vCount = 1;

	for (int i = 0; i < v.size(); i++) {
		if (vCount != v[i]) {
			vCount++;
		}
	}

	if (vCount == qsize) {
		return 1;
	}
}

int IsEmpty(int count) {
	if(count == 0)
		return 1;
}

int main(void) {
	int qsize = 0;
	cin >> qsize;
	int count = 0;

	InitQueue(qsize);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}

	int front = 0;
	int rear = qsize;

	for (int i = 0; i < qsize; i++) {
		Enqueue(i);
	}

	cout << Dequeue();
	cout << IsFull(qsize);
	cout << IsEmpty(count);
}