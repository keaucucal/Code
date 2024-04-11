#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    vector<int> dice = {1, 2, 3, 4, 5, 6};

    int n;
    cin >> n;
    vector<int> value(n + 1);
    value[0] = 1;

    for (int i = 0; i <= n; i++) {
        for (const int &x : dice) {
            if (i - x >= 0) {
                value[i] += value[i - x];
                value[i] %= mod;
            }
        }
    }

    cout << value[n] << '\n';

    return 0;
}
