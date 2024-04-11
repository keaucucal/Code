#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        int pre, l = 0;
        cin >> pre;
        for (int i = 1; i < n; i++) {
            int a;
            cin >> a;

            if (a != pre) {
                while (l < i) {
                    v[l] = i;
                    l++;
                }
                pre = a;
            }
        }

        // for (auto i : v) cout << i << ' ';
        
        int q, r;
        cin >> q;
        while (q--) {
            cin >> l >> r;
            l--, r--;
            if (v[l] > r || v[l] == 0) cout << -1 << ' ' << -1 << '\n';
            else {
                cout << v[l] << ' ' << v[l] + 1 << '\n';
            } 
        }
        
    }
}
