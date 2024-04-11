#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[3] = {0};
    while (n--) {
        for (int i = 0; i < 3; i++) {
            int temp;
            cin >> temp;
            a[i] += temp;
        }
    }

    for (int x : a) {
        if (x != 0) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}
