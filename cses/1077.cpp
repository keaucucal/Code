#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;

int n, k;
multiset<int> low, up;
ll sum_low, sum_up;

void ins(int);
void era(int);
int mid() {
    return k & 1 ? *low.rbegin() : 0;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    vector<int> v(n);
    for (auto &i : v) cin >> i;

    sum_low = sum_up = 0;
    low.insert(v[0]);
    sum_low += v[0];
    for (int i = 1; i < k; i++) {
        ins(v[i]);
    }

    cout << sum_up - sum_low + mid() << ' ';
    for (int i = k; i < n; i++) {
        if (k == 1) {
            ins(v[i]);
            era(v[i - k]);
        } else {
            era(v[i - k]);
            ins(v[i]);
        }

        cout << sum_up - sum_low + mid() << ' '; 
    }

    return 0;
}

inline void ins(int val) {
    int a = *low.rbegin();
    if (val <= a) { // add to low
        low.insert(val);
        sum_low += val;
        if (low.size() > (k + 1) / 2) {
            a = *low.rbegin();
            up.insert(a);
            sum_up += a;
            low.erase(low.find(a));
            sum_low -= a;
        }
    } else { // add to up
        up.insert(val);
        sum_up += val;
        if (up.size() > k / 2) {
            a = *up.begin();
            low.insert(a);
            sum_low += a;
            up.erase(up.find(a));
            sum_up -= a;
        }
    }

    return;
}

inline void era(int val) {
    if (up.find(val) != up.end()) {
        up.erase(up.find(val));
        sum_up -= val;
    } else {
        low.erase(low.find(val));
        sum_low -= val;
    }

    if (low.empty()) {
        int a = *up.begin();
        low.insert(a);
        sum_low += a;
        up.erase(up.find(a));
        sum_up -= a;
    }

    return;
}
