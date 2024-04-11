#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> s;
    vector<int> v(n);
    for (int &x: v)
        cin >> x;

    int ans = 0;
    int l = 0;
    for (int r = 0; r < n; r++) {
        while(s.count(v[r])) {
            s.erase(v[l]);
            l++;
        }

        s.insert(v[r]);
        ans = max(ans, r - l + 1);
    }
    cout << ans << '\n';
    return 0;
}
