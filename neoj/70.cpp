#include <iostream>
#include <queue>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        priority_queue<ll, vector<ll>, greater<ll>> pq;

        int n;
        cin >> n;
        while (n--) {
            int tmp;
            cin >> tmp;
            pq.push(tmp);
        }

        ll ans = 0;
        while (pq.size() > 1) {
            ll a = pq.top();
            pq.pop();
            ll b = pq.top();
            pq.pop();

            ans += a + b;
            pq.push(a + b);
        }

        cout << ans << '\n';
    }

    return 0;
}
