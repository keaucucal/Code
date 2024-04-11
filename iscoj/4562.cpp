#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &i : v) cin >> i;

    sort(v.begin(), v.end());

    for (const auto &i : v) {
        m -= i;
        n--;
        if (m <= 0) break;
    }
    
    cout << n + 1 << '\n';
    return 0;
}
