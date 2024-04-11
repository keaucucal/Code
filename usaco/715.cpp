#include <iostream>
#include <set>
#include <climits>
using namespace std;

int main() {
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);

    int N, K, B;
    cin >> N >> K >> B;

    set<int> s;
    while (B--) {
        int ID;
        cin >> ID;
        s.insert(ID);
    }

    int cnt = 0;
    for (int i = 1; i <= K; i++) {
        cnt += s.count(i);
    }
    int ans = cnt;

    for (int i = K + 1; i <= N; i++) {
        cnt = cnt + s.count(i) - s.count(i - K);
        ans = min(ans, cnt);
    }

    cout << ans << '\n';
}
