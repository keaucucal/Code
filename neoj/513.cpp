#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;
using ll = long long;

#define left first
#define right second

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> ind(n + 1, {0, n + 1}); 
    vector<int> v(n + 1);
    stack<int> st;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];

        while (!st.empty() && v[i] < v[st.top()]) {
            ind[st.top()].right = i;
            st.pop();
        }
        st.push(i);
    }

    stack<int> st2;
    for (int i = n; i >= 1; i--) {
        while (!st2.empty() && v[i] < v[st2.top()]) {
            ind[st2.top()].left = i;
            st2.pop();
        }
        st2.push(i);
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll cur = (ll)v[i] * (ind[i].right - ind[i].left - 1);
        ans = max(ans, cur);
    }

    cout << ans << '\n';
}
