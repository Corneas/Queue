#include <iostream>
using namespace std;
#define NEXT(index, QSIZE) ((index+1)%QSIZE)

typedef struct Queue {
	int* buf;
	int qsize;
	int front;
	int rear;
}Queue;

void InitQueue(Queue* queue, int qsize); // ť �ʱ�ȭ
int IsFull(Queue* queue); // ť�� �� á���� Ȯ��
int IsEmpty(Queue* queue); // ť�� ������� Ȯ��
void Enqueue(Queue* queue, int data); // ť�� ����
int Dequeue(Queue* queue); // ť���� ����

int main(void) {
	int i;
	Queue queue;

	InitQueue(&queue, 10); // ť �ʱ�ȭ �� ����� 10���� ����
	for (i = 1; i < 6; i++) {
		cout << i << "�Է�\n";
		Enqueue(&queue, i);
	}
	cout << endl;

	while (!IsEmpty(&queue)) {
		cout << Dequeue(&queue) << "���\n";
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
		cout << "ť�� �� á��\n";
		return;
	}
	queue->buf[queue->rear] = data;
	queue->rear = NEXT(queue->rear, queue->qsize);
}

int Dequeue(Queue* queue) {
	int re = 0;
	if (IsEmpty(queue)) {
		cout << "ť�� �����\n";
		return re;
	}
	re = queue->buf[queue->front];
	queue->front = NEXT(queue->front, queue->qsize);
	return re;
}