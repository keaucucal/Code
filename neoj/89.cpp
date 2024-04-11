#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<pair<int, int>> v(N);
        for (auto &i : v) cin >> i.second >> i.first; // 1.Eating time 2.Prepare time
        
        sort(v.begin(), v.end(), greater<pair<int, int>>());

        int cur = 0;
        int ans = 0;
        for (const auto &i : v) {
            cur += i.second;
            ans = max(ans, cur + i.first);
        }

        cout << ans << '\n';
    }

    return 0;
}
