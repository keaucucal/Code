// ISCOJ 4477 青蛙的青蛙下蛋
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << __builtin_popcount(n) << '\n';
    }

    return 0;
}
