#include <iostream>

using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Class for the stack implemented using a linked list
class Stack {
private:
    Node* top; // Pointer to the top of the stack

public:
    // Constructor to initialize an empty stack
    Stack() : top(nullptr) {}

    // Function to push a value onto the stack
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    // Function to pop a value from the stack
    int pop() {
        if (isEmpty()) {
            cerr << "Stack Underflow" << endl;
            return -1; // Error value for underflow
        }

        int poppedValue = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;

        return poppedValue;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Function to display the stack
    void display() {
        Node* current = top;
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << " ";
            }
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;

    int inputValue;
    cin >> inputValue;

    while (inputValue >= 0) {
        stack.push(inputValue);
        cin >> inputValue;
    }

    if (!stack.isEmpty()) {
        stack.display();
    } else {
        cout << "Stack Underflow" << endl;
    }

    return 0;
}
