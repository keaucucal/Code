#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int &c : coins) cin >> c;

    vector<int> count(x + 1);
    count[0] = 1;
    for (int value = 1; value <= x; value++) {
        for (const int &c : coins) {
            if (value - c >= 0)
                count[value] += count[value - c];
            count[value] %= mod;
        }
    }

    cout << count[x] << '\n';

    return 0;
}
