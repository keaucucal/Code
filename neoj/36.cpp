#include <iostream>
#include <stack>
using namespace std;

int main() {
    int t;
    cin >> t;

    stack<int> st;
    while (t--) {
        int a;
        cin >> a;
        if (a == 1) {
            int n;
            cin >> n;
            st.push(n);
        } else {
            if (st.empty()) cout << "empty!\n";
            else {
                cout << st.top() << '\n';
                st.pop();
            }
        }
    }
}
