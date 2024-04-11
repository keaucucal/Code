#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    stack<int> st;

    bool flag = true;
    while (n--) {
        int a;
        cin >> a;
        if (a < 0) {
            if (st.empty() || st.top() + a != 0) flag = false;
            else st.pop();
        } else {
            st.push(a);
        }
    }

    if (!st.empty()) flag = false;
    cout << (flag ? "weed" : "lose light light") << '\n';
}
