#include <iostream>
#include <set>
using namespace std;

inline bool possible(set<int> a, set<int> b, int k) {
    int ca = 0, cb = 0;
    for (int i = 1; i <= k; i++) {
        if (a.find(i) != a.end()) {
            ca++;
        }
        if (b.find(i) != b.end()) {
            cb++;
        }
        if (a.find(i) == a.end() && b.find(i) == b.end()) return false;
    }

    return ca >= k / 2 && cb >= k / 2;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        set<int> a, b;
        
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            a.insert(temp);
        }
        for (int i = 0; i < m; i++) {
            int temp;
            cin >> temp;
            b.insert(temp);
        }

        cout << (possible(a, b, k) ? "YES" : "NO") << '\n';
    }
}
