#include <iostream>
#include <stack>
using namespace std;

int countMinReversals(string str) {
    stack<char> st;
    int ans = 0;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '{')
            st.push(str[i]);
        else {
            if (!st.empty())
                st.pop();
            else {
                st.push('{');
                ans++;
            }
        }
    }

    if (st.size() % 2 != 0)
        return -1;

    ans += st.size() / 2;

    return ans;
}

int main() {
    string expr;
    cout << "Enter the expression: ";
    cin >> expr;

    int result = countMinReversals(expr);

    cout << "Output: " << result << endl;

    return 0;
}
