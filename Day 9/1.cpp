#include<iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Stack class using linked list
class Stack {
private:
    Node* top;

public:
    // Constructor
    Stack() {
        top = nullptr;
    }

    // Function to push element onto the stack
    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    // Function to pop element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;  // Return a special value to indicate underflow
        }

        Node* temp = top;
        int poppedValue = temp->data;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Function to display the stack elements
    void display() {
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Function to get the top element of the stack
    int getTop() {
        if (isEmpty()) {
            return -1;  // Return a special value to indicate empty stack
        }
        return top->data;
    }
};

int main() {
    Stack stack;
    
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Stack Underflow\n";
        return 0;
    }

    cout << "Enter the stack elements: ";
    for (int i = 0; i < n; ++i) {
        int element;
        cin >> element;
        stack.push(element);
    }

    cout << "Output:\n";
    stack.display();
    cout << "Top element is " << stack.getTop() << endl;

    int poppedValue = stack.pop();
    if (poppedValue != -1) {
        stack.display();
        cout << "Top element is " << stack.getTop() << endl;
    }

    return 0;
}

/*Reference Links
https://www.geeksforgeeks.org/implement-a-stack-using-singly-linked-list/
http://www.btechsmartclass.com/data_structures/stack-using-linked-list.html
*/