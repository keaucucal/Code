#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (auto &i : x) cin >> i;
    for (auto &i : y) cin >> i;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dx = x[j] - x[i];
            int dy = y[j] - y[i];

            int cur = dx * dx + dy * dy;
            ans = max(ans, cur);
        }
    }

    cout << ans << '\n';
}
