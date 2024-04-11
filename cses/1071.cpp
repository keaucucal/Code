#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    long long y, x;
    while (t--) {
        cin >> y >> x;
        if (y > x) {
            if (y & 1) cout << y * y - y * 2 + x + 1 << '\n';
            else cout << y * y - x + 1 << '\n';
        } else {
            if (x & 1) cout << x * x - y + 1 << '\n';
            else cout << x * x - x * 2 + y + 1 << '\n'; 
        }
    }

    return 0;
}
