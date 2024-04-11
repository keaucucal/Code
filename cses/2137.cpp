#include <iostream>
#include <vector>
#include <bitset>
#pragma GCC target("popcnt")
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<bitset<3000>> bs(n);
    for (auto &i : bs) cin >> i;

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long bit = (bs[i] & bs[j]).count();
            ans += bit * (bit - 1) / 2; 
        }
    }

    cout << ans << '\n';
}
