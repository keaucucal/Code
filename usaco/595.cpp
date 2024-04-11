#include <iostream>
#include <vector>
using namespace std;

const int mod = 7;

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    int N;
    cin >> N;

    vector<int> v(mod, -1);

    int cur = 0, ans = 0;
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;

        cur = (cur + a) % mod;
        if (v[cur] == -1) {
            v[cur] = i;
        } else {
            ans = max(ans, i - v[cur]);
        }
    }

    cout << ans << '\n';
}
