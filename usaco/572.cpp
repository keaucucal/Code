#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    int N, Q;
    cin >> N >> Q;
    vector<int> a(N + 1), b(N + 1), c(N + 1);

    for (int i = 1; i <= N; i++) {
        int t;
        cin >> t;
        switch (t) {
            case 1:
                a[i]++;
                break;
            case 2:
                b[i]++;
                break;
            case 3:
                c[i]++;
                break;
        }

        a[i] += a[i - 1];
        b[i] += b[i - 1];
        c[i] += c[i - 1];
    }

    while (Q--) {
        int l, r;
        cin >> l >> r;
        l--;
        cout << a[r] - a[l] << ' ' << b[r] - b[l] << ' ' << c[r] - c[l] << '\n';
    }
}
