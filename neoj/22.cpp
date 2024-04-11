#include <iostream>
#include <stack>
using namespace std;

void solve() {
    int n;
    cin >> n;

    stack<int> st, times;
    long long ans = 0;
   
    while (n--) {
        int a;
        cin >> a;

        while (!st.empty() && a > st.top()) {
            ans++;
            st.pop();
            times.pop();
        }

        ans += (!st.empty());
        
        if (st.size() > 1 && a == st.top()) {
            times.push(times.top() + 1);
            ans += times.top();
        } else times.push(0);

        st.push(a);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
