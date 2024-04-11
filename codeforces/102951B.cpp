#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (auto &i : v) cin >> i;

    sort(v.begin(), v.end());

    int sum = 0, ans = 0;
    for (const auto &i : v) {
        sum += i;
        if (sum > x) break;
        ans++;
    }

    cout << ans << '\n';
}
