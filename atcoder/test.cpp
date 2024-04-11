// check prime
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<bool> v(n + 1, true);
    
    for (int i = 2; i <= n; i++) {
        if (v[i]) {
            for (int j = i; j <= n; j += i) {
                v[j] = false;
            }
        }
    }

    cout << (v[n] ? "PRIME" : "NOT PRIME") << '\n';
}
