// TIOJ 1072.A.誰先晚餐 
// Greedy
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    while (cin >> N) {
        if (N == 0) break;


        vector<pair<int, int>> v(N);
        for (auto &i : v) {
            cin >> i.second >> i.first; // 1.Eating time / 2.Preparing time
        }

        sort(v.begin(), v.end(), greater<pair<int, int>>());

        int ans = 0;
        int cur = 0;
        for (auto &i : v) {
            cur += i.second;
            ans = max(ans, cur + i.first);
        }

        cout << ans << '\n';
    }
    
    return 0;
}
