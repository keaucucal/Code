#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

const int INF = INT_MAX;

int n, q;
vector<int> tree;
void update(int, int);
int mi(int, int);

int main() {
    cin >> n >> q;
    tree.resize(n * 2);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        update(i, x);
    }

    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) update(a, b);
        else cout << mi(a, b) << '\n';
    }
}

inline int mi(int a, int b) {
    a += n, b += n;
    int ans = INF;
    while (a <= b) {
        if (a % 2 == 1) ans = min(ans, tree[a++]);
        if (b % 2 == 0) ans = min(ans, tree[b--]);
        a /= 2, b /= 2;
    }
    return ans;
}

inline void update(int k, int x) {
    k += n;
    tree[k] = x;
    for (k /= 2; k >= 1; k /= 2) {
        tree[k] = min(tree[2 * k], tree[2 * k + 1]);
    }
}
