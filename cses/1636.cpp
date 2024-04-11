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
    for (const int &c : coins) {
        for (int i = 1; i <= x; i++) {
            if (i - c >= 0) {
                count[i] = (count[i] + count[i - c]) % mod;
            }
        }
    }

    cout << count[x] << '\n';
    return 0;
}
