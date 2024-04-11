#include <iostream>
#include <stack>
using namespace std;

void solve() {
    int n;
    cin >> n;
    stack<int> st;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        st.push(a);
    } 

    stack<int> cur;
    int cnt = n;
    while (!st.empty()) {
        cur.push(st.top());
        st.pop();
        
        while (!cur.empty() && cur.top() == cnt) {
            cnt--;
            cur.pop();
        }
    }

    cout << (cur.empty() ? "Yes" : "No") << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
