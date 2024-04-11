#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> v;
vector<ll> tree;
int n, q;

void update(int k, int x) {
    int diff = x - v[k];
    v[k] = x;
    while (k <= n) {
        tree[k] += diff;
        k += k & -k;
    }
}

ll query(int k) {
    ll sum = 0;
    while (k > 0) {
        sum += tree[k];
        k -= k & -k;
    }
    return sum;
}

int main() {
    cin >> n >> q;
    v.resize(n + 1);
    tree.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        update(i, x);
    }

    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) update(a, b);
        else cout << query(b) - query(a - 1) << '\n';
    }
}
