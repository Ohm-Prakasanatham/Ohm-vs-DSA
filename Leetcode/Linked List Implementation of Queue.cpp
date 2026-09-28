
#include <iostream>
using namespace std;

class Queue {
    struct Node {
        int data;
        Node* next;

        Node(int x) {
            data = x;
            next = nullptr;
        }
    };

    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Insert element
    void push(int x) {
        Node* newNode = new Node(x);

        // If queue is empty
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    // Remove element
    void pop() {
        if (front == nullptr) {
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = front;
        front = front->next;

        // Queue becomes empty
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    // Get front element
    int peek() {
        if (front == nullptr) {
            cout << "Queue is empty\n";
            return -1;
        }

        return front->data;
    }

    // Check if empty
    bool isEmpty() {
        return front == nullptr;
    }
};

