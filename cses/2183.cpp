#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v) cin >> i;

    sort(v.begin(), v.end());

    long long sum = 0;
    for (const auto &i : v) {
        if (sum + 1 < i) break;
        sum += i;
    }

    cout << sum + 1 << '\n';
    return 0;
}
