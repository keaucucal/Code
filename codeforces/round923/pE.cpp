#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> v(n);
        int cnt = 1;
        for (int i = 0; i < k; i += 2) {
            for (int j = i; j < n; j += k) {
                v[j] = cnt++;
            }
        }
        for (int i = n - k + !(n & 1); i < n; i += 2) {
            for (int j = i; j >= 0; j -= k) {
                v[j] = cnt++;
            }
        }
        
        for (auto i : v) cout << i << ' ';
        cout << '\n';
    }
}
