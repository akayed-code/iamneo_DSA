#include <iostream>
#include <stack>
using namespace std;

// Function to count the minimum number of reversals required
int countMinReversals(string str) {
    stack<char> st; // Stack to keep track of opening brackets
    int ans = 0;    // Variable to store the answer

    // Loop through each character of the string
    for (int i = 0; i < str.size(); i++) {
        // If '{' is encountered, push it to the stack
        if (str[i] == '{')
            st.push(str[i]);
        else {
            // If '}' is encountered
            // Check if there is a matching '{' in the stack
            if (!st.empty())
                st.pop();
            else {
                // If the stack is empty, change '}' to '{',
                // push it to the stack, and increment ans
                st.push('{');
                ans++;
            }
        }
    }

    // If the stack size is odd, return -1 (imbalanced expression)
    if (st.size() % 2 != 0)
        return -1;

    // Increment ans by (stackSize / 2)
    ans += st.size() / 2;

    return ans;
}

int main() {
    string expr;
    
    // Prompt the user to enter the expression
    cout << "Enter the expression: ";
    cin >> expr;

    // Call the function and display the result
    int result = countMinReversals(expr);
    cout << "Output: " << result << endl;

    return 0;
}
