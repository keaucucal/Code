#include <iostream>
#include <vector>
using namespace std;

struct tree {
    int n;
    vector<int> v;
    
    tree(int L) : n(L), v(L << 1) {
        for (int i = n; i < n * 2; i++) {
            cin >> v[i];
        }
        for (int i = n - 1; i > 0; i--) {
            v[i] = v[i * 2] + v[i * 2 + 1];
        }
        
        for (auto i : v) cout << i << ' ';
        cout << '\n';
    }

    int query(int l, int r) {
        int ans = 0;
        l += n, r += n;
        while (l <= r) {
            cout << l << ' ' << r << '\n';
            if (l & 1) ans += v[l++];
            if (!(r & 1)) ans += v[r--];
            l >>= 1, r >>= 1;
            cout << ans << '\n';
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    tree v(n);
    cout << v.query(0, 2); 
}
