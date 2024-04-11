#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int n, q;
vector<ll> tree;
void update(int, int);
ll query(int);

int main() {
    cin >> n >> q;
    tree.resize(n + 2);
    int pre = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        update(i, x - pre);
        pre = x;
    }

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            update(a, u);
            update(b + 1, -u);
        } else {
            int k;
            cin >> k;
            cout << query(k) << '\n';
        }
    }
}

inline void update(int k, int u) {
    while (k <= n) {
        tree[k] += u;
        k += k & -k;
    }
}

inline ll query(int k) {
    ll sum = 0;
    while (k > 0) {
        sum += tree[k];
        k -= k & -k;
    }
    return sum;
}
