#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, n;
    cin >> x >> n;

    set<int> lights = {0, x};
    multiset<int> passage = {x};

    while (n--) {
        int p;
        cin >> p;

        auto r = lights.upper_bound(p);
        auto l = r;
        l--;

        lights.insert(p);
        passage.erase(passage.find(*r - *l));
        passage.insert(*r - p);
        passage.insert(p - *l);

        cout << *passage.rbegin() << ' ';
    }
}
