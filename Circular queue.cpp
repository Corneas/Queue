#include <iostream>
using namespace std;

class Queue { // Queue Ŭ���� ����
public:
    int front; // ���� �ε��� ���� ����Ŵ
    int rear; // ���� �ֱٿ� ������ �ڷḦ ����Ŵ
    int* buf; // �����
    int qsize; // ť�� ũ��

    void InitQueue(int size) {
        buf = new int[size]; //ũ�Ⱑ qsize�� �迭 �Ҵ�
        qsize = size;
        front = rear = 0;
    }
    int IsFull() {
        return (rear + 1) % qsize == front;
    }
    int IsEmpty() {
        return front == rear;
    }
    void Enqueue(int data) {
        if (IsFull()) { // ť�� �� á�� ��
            cout << "ť�� �� á��\n";
            return;
        }
        rear = (rear + 1) % qsize;
        buf[rear] = data; // rear �ε����� ������Ű�� �ڷ� ����
    }
    int Dequeue() {
        if (IsEmpty()) { // ť�� ����� ��
            cout << "ť�� �����\n";
            return -1;
        }
        front = (front + 1) % qsize;
        return
            buf[front];
    }
};

void print_queue(Queue q)
{
    cout << "front=" << q.front << " " << "rear = " << q.rear << " "; // ���� front, rear �� ���
    if (!q.IsEmpty()) { // ť �ȿ� �ִ� ���ҵ��� ������� �ϳ��� ���
        int i = q.front;
        do {
            i = (i + 1) % q.qsize;
            cout << " | " << q.buf[i];
            if (i == q.rear) {
                cout << " | ";
                break;
            }
        } while (i != q.front);
    }
    cout << endl;
}

int get_count(Queue q) {
    
    if (q.front > q.rear) {
        return q.rear + 1;
    }
    else {
        return q.rear - q.front;
    }
}


int main(void) {
    Queue q1;
    q1.InitQueue(4);
    for (int i = 1; i < 5; i++) { 
        q1.Enqueue(i);
        print_queue(q1);
        cout << "ť�� ���� : " << get_count(q1) << endl;
    }
    cout << endl;
    for (int i = 1; i < 5; i++) { 
        q1.Dequeue();
        print_queue(q1);
        cout << "ť�� ���� : " << get_count(q1) << endl;
    }       
    cout << endl;
    for (int i = 1; i < 5; i++) {              
        q1.Enqueue(i);                         
        print_queue(q1);                       
        cout << "ť�� ���� : " << get_count(q1) << endl;
    }
}