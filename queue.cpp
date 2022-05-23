#include <iostream>
using namespace std;
#define NEXT(index, QSIZE) ((index+1)%QSIZE)

typedef struct Queue {
	int* buf;
	int qsize;
	int front;
	int rear;
}Queue;

void InitQueue(Queue* queue, int qsize); // 큐 초기화
int IsFull(Queue* queue); // 큐가 꽉 찼는지 확인
int IsEmpty(Queue* queue); // 큐가 비었는지 확인
void Enqueue(Queue* queue, int data); // 큐에 보관
int Dequeue(Queue* queue); // 큐에서 꺼냄

int main(void) {
	int i;
	Queue queue;

	InitQueue(&queue, 10); // 큐 초기화 및 사이즈를 10으로 설정
	for (i = 1; i < 6; i++) {
		cout << i << "입력\n";
		Enqueue(&queue, i);
	}
	cout << endl;

	while (!IsEmpty(&queue)) {
		cout << Dequeue(&queue) << "출력\n";
	}
	cout << endl;
	return 0;
}

void InitQueue(Queue* queue, int qsize) {
	queue->buf = new int[qsize];
	queue->qsize = qsize;
	queue->front = queue->rear = -1;
}

int IsFull(Queue* queue) {
	return queue->rear == queue->qsize;
}

int IsEmpty(Queue* queue) {
	return queue->front == queue->rear;
}

void Enqueue(Queue* queue, int data) {
	if (IsFull(queue)) {
		cout << "큐가 꽉 찼음\n";
		return;
	}
	queue->buf[queue->rear] = data;
	queue->rear = NEXT(queue->rear, queue->qsize);
}

int Dequeue(Queue* queue) {
	int re = 0;
	if (IsEmpty(queue)) {
		cout << "큐가 비었음\n";
		return re;
	}
	re = queue->buf[queue->front];
	queue->front = NEXT(queue->front, queue->qsize);
	return re;
}