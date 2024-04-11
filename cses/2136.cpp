#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            char c;
            cin >> c;
            if (c - '0') v[i] |= (1 << j);
        }
    }
    
    int ans = 31;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans = min(ans, __builtin_popcount(v[i] ^ v[j])); 
        }
    }

    cout << ans << '\n';
}
