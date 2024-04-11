#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int N;
    cin >> N;
    vector<int> v(N + 1);
    for (int i = 1; i <= N; i++) cin >> v[i];

    vector<int> pre(N + 1), suf(N + 2);
    for (int i = 1; i <= N; i++) pre[i] = gcd(pre[i - 1], v[i]);
    for (int i = N; i >= 1; i--) suf[i] = gcd(suf[i + 1], v[i]);

    int ans = 0;
    for (int i = 1; i <= N; i++) ans = max(ans, gcd(pre[i - 1], suf[i + 1]));

    cout << ans << '\n';
}
