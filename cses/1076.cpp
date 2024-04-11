#include <iostream>
#include <set>
#include <vector>
using namespace std;

int k, n;
multiset<int> low;
multiset<int> up;

void ins(int);
void era(int);

int main() {
    cin >> n >> k;
    vector<int> v(n);
    for (auto &i : v) cin >> i;

    low.insert(v[0]);
    for (int i = 1; i < k; i++) {
        ins(v[i]);
    }

    cout << *low.rbegin() << ' ';
    for (int i = k; i < n; i++) {
        if (k == 1) {
            ins(v[i]);
            era(v[i - k]);
        } else {
            era(v[i - k]);
            ins(v[i]);
        }

        cout << *low.rbegin() << ' ';
    }

    return 0;
}

inline void ins(int val) {
    int a = *low.rbegin();
    if (val < a) { // add to low
        low.insert(val);
        if (low.size() > (k + 1) / 2) {
            up.insert(*low.rbegin());
            low.erase(low.find(*low.rbegin()));
        }
    } else { // add to up
        up.insert(val);
        if (up.size() > k / 2) {
            low.insert(*up.begin());
            up.erase(up.find(*up.begin()));
        }
    }
}

inline void era(int val) {
    if (up.find(val) != up.end()) up.erase(up.find(val));
    else low.erase(low.find(val));
    if (low.empty()) {
        low.insert(*up.begin());
        up.erase(up.find(*up.begin())); 
    }
}
