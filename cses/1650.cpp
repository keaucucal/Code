#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n + 1);
    v[0] = 0;
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        v[i] = v[i - 1] ^ temp;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << (v[l - 1] ^ v[r]) << '\n';
    }
    
    return 0;        
}
