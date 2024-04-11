#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int ans;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            bool b;
            cin >> b;
            if (b) ans = abs(i - 2) + abs(j - 2);
        }
    }

    cout << ans << '\n';
    return 0;
}
