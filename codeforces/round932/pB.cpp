#include <iostream>
#include <vector>
#include <set>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n + 1), v(n);
    for (auto &i : v) {
        cin >> i;
        cnt[i]++;
    } 

    int mex = 0;
    while (cnt[mex]) mex++;

    int cur = 0;
    vector<int> b(n + 1);
    for (int i = 0; i < n; i++) {
        int a = v[i];

        b[a]++;
        while (b[cur]) cur++;
        cnt[a]--;
        if (cnt[a] == 0 && mex > a) mex = a;
    
        if (mex == cur) {
            cout << 2 << '\n';
            cout << 1 << ' ' << i + 1 << '\n';
            cout << i + 2 << ' ' << n << '\n';
            return;
        }
    }

    cout << "-1\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
