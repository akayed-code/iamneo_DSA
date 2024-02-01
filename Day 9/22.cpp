#include <iostream>

using namespace std;

// Node structure for the linked list
struct Node {
    int data;        // Data of the node
    Node* next;      // Pointer to the next node in the list
};

// Class for the stack implemented using a linked list
class Stack {
private:
    Node* top;        // Pointer to the top of the stack

public:
    // Constructor to initialize an empty stack
    Stack() : top(nullptr) {}

    // Function to push a value onto the stack
    void push(int value) {
        // Create a new node
        Node* newNode = new Node();
        newNode->data = value;  // Set the data of the new node
        newNode->next = top;    // Make the new node point to the current top
        top = newNode;          // Update the top to the new node
    }

    // Function to pop a value from the stack
    int pop() {
        // Check for underflow (empty stack)
        if (isEmpty()) {
            cerr << "Stack Underflow" << endl;
            return -1;  // Error value for underflow
        }

        int poppedValue = top->data;  // Get the data of the top node
        Node* temp = top;             // Save the current top node
        top = top->next;              // Update the top to the next node
        delete temp;                  // Free the memory of the popped node

        return poppedValue;           // Return the popped value
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;  // Stack is empty if top is null
    }

    // Function to display the stack
    void display() {
        Node* current = top;  // Start from the top of the stack

        // Iterate through the stack and print each element
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << " ";
            }
            current = current->next;  // Move to the next node
        }

        cout << endl;
    }
};

int main() {
    Stack stack;  // Create a stack object

    int inputValue;
    cin >> inputValue;  // Read the first input value

    // Keep reading input values until a negative value is entered
    while (inputValue >= 0) {
        stack.push(inputValue);  // Push the input value onto the stack
        cin >> inputValue;       // Read the next input value
    }

    // Check if the stack is not empty and display its contents
    if (!stack.isEmpty()) {
        stack.display();
    } else {
        cout << "Stack Underflow" << endl;  // Display underflow message
    }

    return 0;
}
