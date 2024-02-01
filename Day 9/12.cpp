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
    
    //Enter the number of elements
    int n;
    cin >> n;

    if (n <= 0) {
        cout << "Stack Underflow\n";
        return 0;
    }

    //Enter the stack elements
    for (int i = 0; i < n; ++i) {
        int element;
        cin >> element;
        stack.push(element);
    }

    //Output
    stack.display();
    
    //Top element is
    cout << stack.getTop() << endl;

    int poppedValue = stack.pop();
    if (poppedValue != -1) {
        stack.display();
        
        //Top element is
        cout << stack.getTop() << endl;
    }

    return 0;
}

/*INPUT
5
12 89 45 32 65

OUTPUT

65 32 45 89 12 
65
32 45 89 12 
32*/