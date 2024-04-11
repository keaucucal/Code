#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int n;
vector<int> v;

bool check(int cur, int rad) {
    int next = 0;
    while (cur < v.back()) {
        while (next + 1 < n && cur + rad >= v[next + 1]) next++;
        
        if (v[next] == cur) {
            return false;
        }

        cur = v[next];
        rad -= 2;
    }

    return true;
}

int bs(int l, int r, function<bool(int)> f) {
    while (l < r) {
        int mid = l + (r - l) / 2;

        if (f(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    return l;
}

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    cin >> n;
    v.resize(n);
    for (auto &i : v) {
        cin >> i;
        i *= 2;
    }

    sort(v.begin(), v.end());

    int ans = bs(0, 2e9, [&](int x) {
        int leftmost = bs(v.front(), v.back(), [&](int start) {
            return check(start, x);
        });
        for (int &x : v) x *= -1;
        reverse(v.begin(), v.end());

        bool ret = (check(-leftmost, x) ? true : false);

        reverse(v.begin(), v.end());
        for (int &x : v) x *= -1;

        return ret;
    });

    cout << ans / 2 << '.' << (ans & 1 ? '5' : '0') << '\n';
}
