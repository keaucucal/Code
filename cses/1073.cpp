#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;

    multiset<int> s;
    int k;
    cin >> k;
    s.insert(k);
    for (int i = 1; i < n; i++) {
        cin >> k;

        auto it = s.upper_bound(k);
        if (it != s.end()) s.erase(it);

        s.insert(k);
    }

    cout << s.size() << '\n';
}
