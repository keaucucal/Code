#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

using ll = long long;

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll N;
        cin >> N;
        
        string ans;

        if (N == 1) cout << 1 << '\n';
        while (N != 1) {
            ll i = 9;
            while (i >= 2 && N % i != 0) i--;

            if (i == 1) {
                cout << -1 << '\n';
                ans.clear();
                break;
            }

            ans += to_string(i);
            N /= i;
        }
        
        reverse(ans.begin(), ans.end());
        if (ans.length()) cout << ans << '\n';
    }

    return 0;
}
