#include <iostream>
using namespace std;

class Stack {
    int arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top == 99) {
            cout << "Stack Overflow\n";
            return;
        }

        arr[++top] = x;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }

        top--;
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return -1;
        }

        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};
