#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> v(n + 1);
    v[0] = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        v[i] = v[i - 1] + x;
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << v[b] - v[a - 1] << '\n';
    }

    return 0;
}
