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
        for (auto &i : v) cin >> i;

        int l = 0, r = n - 1;
        if (v[l] == v[r]) {
            int t = v[l];
            while (l < n && v[l] == t) l++;
            while (r >= 0 && v[r] == t) r--;
        } else {
            int a = v[l], b = v[r];
            while (l < n && v[l] == a) l++;
            while (r >= 0 && v[r] == b) r--;
            if (l > n - 1 - r) r = n - 1;
            else l = 0;
        }
    
        if (r < l) cout << "0\n";
        else cout << r - l + 1 << '\n';
    }
}
