// TIOJ 1861.蘿莉（菠）切割問題
// Greedy, priority_queue
#include <iostream>
#include <queue>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    while (cin >> N) {
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        while (N--) {
            int tmp;
            cin >> tmp;
            pq.push(tmp);
        }

        ll sum = 0;
        while (pq.size() > 1) {
            ll a = pq.top();
            pq.pop();
            ll b = pq.top();
            pq.pop();

            sum += a + b;
            pq.push(a + b);
        }

        cout << sum << '\n';
    }

    return 0;
}
