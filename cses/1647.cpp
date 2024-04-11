#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int &x : v) cin >> x;
    vector<vector<int>> st;

    int k = log2(n);
    st.assign(n, vector<int>(k + 1));
    for (int i = 0; i < n; i++) {
        st[i][0] = v[i];
    }
    for (int j = 1; j <= k; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        int l = log2(b - a + 1);
        cout << min(st[a][l], st[b - (1 << l) + 1][l]) << '\n';
    }

    return 0;
}
