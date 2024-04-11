#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        long long sum = 0;
        for (auto &i : v) {
            cin >> i;
            sum += i;
        }

        if (sum % n) {
            cout << "NO\n";
            continue;
        }
        sum /= n; // the amount of water need to reach
    
        int cnt = 0;
        for (auto i : v) {
            cnt += i - sum;
            if (cnt < 0) break; 
        }

        if (cnt < 0) cout << "NO\n";
        else cout << "YES\n";
    }
}
