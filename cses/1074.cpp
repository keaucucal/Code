#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v) {
        cin >> i;
    }

    sort(v.begin(), v.end());

    long long sum = 0;
    int cost = v[n / 2];
    for (int i = 0; i < n / 2; i++) sum += cost - v[i];
    for (int i = n / 2 + 1; i < n; i++) sum += v[i] - cost;

    cout << sum << '\n';
    return 0;
}
