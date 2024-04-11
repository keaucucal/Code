#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    string s2 = s;
    reverse(s2.begin(), s2.end());

    if (s2 < s) cout << s2 << s << '\n';
    else cout << s << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
