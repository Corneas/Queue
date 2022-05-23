#include <iostream>
using namespace std;

class Queue { // Queue 클래스 정의
public:
    int front; // 꺼낼 인덱스 앞을 가리킴
    int rear; // 가장 최근에 보관된 자료를 가리킴
    int* buf; // 저장소
    int qsize; // 큐의 크기

    void InitQueue(int size) {
        buf = new int[size]; //크기가 qsize인 배열 할당
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
        if (IsFull()) { // 큐가 꽉 찼을 때
            cout << "큐가 꽉 찼음\n";
            return;
        }
        rear = (rear + 1) % qsize;
        buf[rear] = data; // rear 인덱스를 증가시키고 자료 보관
    }
    int Dequeue() {
        if (IsEmpty()) { // 큐가 비었을 때
            cout << "큐가 비었음\n";
            return -1;
        }
        front = (front + 1) % qsize;
        return
            buf[front];
    }
};

void print_queue(Queue q)
{
    cout << "front=" << q.front << " " << "rear = " << q.rear << " "; // 현재 front, rear 값 출력
    if (!q.IsEmpty()) { // 큐 안에 있는 원소들을 순서대로 하나씩 출력
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
        cout << "큐의 개수 : " << get_count(q1) << endl;
    }
    cout << endl;
    for (int i = 1; i < 5; i++) { 
        q1.Dequeue();
        print_queue(q1);
        cout << "큐의 개수 : " << get_count(q1) << endl;
    }       
    cout << endl;
    for (int i = 1; i < 5; i++) {              
        q1.Enqueue(i);                         
        print_queue(q1);                       
        cout << "큐의 개수 : " << get_count(q1) << endl;
    }
}