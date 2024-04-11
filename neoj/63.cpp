#include <iostream>
#include <vector>
using namespace std;

int k;
vector<int> v;
vector<int> cur;
void solve(int cur_n, int cur_k) { // cur_n 取了幾個 / cur_k 現在指向
    if (cur_n == 6) {
        cout << cur[0];
        for (int i = 1; i < 6; i++) {
            cout << ' ' << cur[i];
        }
        cout << '\n';
        return;
    }

    if (cur_k == k) return;

    cur.push_back(v[cur_k]);
    solve(cur_n + 1, cur_k + 1);
    cur.pop_back();

    solve(cur_n, cur_k + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        cin >> k;
        
        v.resize(k);
        for (auto &i : v) cin >> i;
        
        solve(0, 0);
    }

    return 0;
}
