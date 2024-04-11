#include <iostream>
#include <set>
using namespace std;

string s;
set<int> diff;
multiset<int> dist;

void modify(int x) {
    if (x == 0 || x == s.length()) return;

    auto it = diff.find(x);
    if (it == diff.end()) {
        it = diff.insert(x).first;
        int a = *prev(it), b = *next(it);
        dist.erase(dist.find(b - a));
        dist.insert(x - a), dist.insert(b - x);
    } else {
        int a = *prev(it), b = *next(it);
        dist.erase(dist.find(x - a));
        dist.erase(dist.find(b - x));
        dist.insert(b - a);
        diff.erase(it);
    }
}

int main() {
    // necessary
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    diff.insert(0);
    diff.insert(s.length());
    for (int i = 1; i < s.length(); i++) {
        if (s[i] != s[i - 1]) diff.insert(i);
    }

    for (auto it = diff.begin(); next(it) != diff.end(); it++) {
        dist.insert(*next(it) - *it);
    }

    int m;
    cin >> m;
    while (m--) {
        int x;
        cin >> x;

        modify(x - 1);
        modify(x);

        cout << *dist.rbegin() << ' ';
    }
}
