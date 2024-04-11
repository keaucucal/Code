#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    multiset<int> ms;
    while (n--) {
        int h;
        cin >> h;
        ms.insert(h);
    }

    while (m--) {
        int t;
        cin >> t;
        auto it = ms.upper_bound(t);
        if (it == ms.begin()) {
            cout << -1 << '\n';
        } else {
            it--;
            cout << *it << '\n';
            ms.erase(it);
        }
    }

    return 0;
}
