#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;


int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &i : v) cin >> i;
    sort(v.begin(), v.end());

    while (--n) {
        vector<ll> next;
        next.reserve(n);
        priority_queue<tuple<ll, int, int>> pq;

        for (int i = 0; i < n; i++) {
            pq.push({-(v[i] + v[i + 1]), i, i + 1});
        }

        for (int i = 0; i < n; i++) {
            ll val, l, r;
            tie(val, l, r) = pq.top();
            val *= -1;
            pq.pop();

            next.push_back(val);

            if (r + 1 < v.size())
                pq.push({-(v[l] + v[r + 1]), l, r + 1});
        }

        ll remainder = next[0] / mod;
        for (auto &i : next) i -= remainder * mod;
        v = next;
    }
    
    cout << v[0];
}
