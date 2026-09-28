#include <iostream>
using namespace std;

class Queue {
    int arr[100];
    int front;
    int rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    void push(int x) {
        if (rear == 99) {
            cout << "Queue Overflow\n";
            return;
        }

        arr[++rear] = x;
    }

    void pop() {
        if (front > rear) {
            cout << "Queue Underflow\n";
            return;
        }

        front++;
    }

    int peek() {
        if (front > rear) {
            cout << "Queue is empty\n";
            return -1;
        }

        return arr[front];
    }

    bool isEmpty() {
        return front > rear;
    }
};
