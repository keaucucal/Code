#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int sum = 0;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum += a;
        if (a % 3 == 1) flag = true;
    }

    switch (sum % 3) {
        case 0:
            cout << 0 << '\n';
            break;
        case 1:
            if (flag) cout << 1 << '\n';
            else cout << 2 << '\n';
            break;
        case 2:
            cout << 1 << '\n';
            break;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
