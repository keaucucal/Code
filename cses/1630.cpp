#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n); // first->duration / second->deadline
    for (auto &i : v) cin >> i.first >> i.second;
    sort(v.begin(), v.end());

    long long ans = 0, cur = 0;
    for (auto i : v) {
        cur += i.first;
        ans += i.second - cur;
    }
    
    cout << ans << '\n';
}
