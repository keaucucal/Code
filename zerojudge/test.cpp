#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

inline void check(int &a, int &b, int way) {
    switch (way) {
        case 1:
            a &= b;
            break;
        case 2:
            a |= b;
            break;
        case 3:
            a ^= b;
            break;
    }
}

int main() {
    int p, q, r, m;
    cin >> p >> q >> r >> m;
    vector<int> num(p + q + r + 1, -1);
    for (int i = 1; i <= p; i++) {
        cin >> num[i];
    }
    vector<int> gate(p + q + r + 1);
    for (int i = p + 1; i <= p + q; i++) {
        cin >> gate[i];
    }

    vector<int> dir[p + q + 1];
    while (m--) {
        int u, v;
        cin >> u >> v;
        dir[u].push_back(v);
    }

    queue<int> que;
    for (int i = 1; i <= p; i++) {
        for (auto x : dir[i]) {
            que.push(x);
            if (num[x] == -1) {
                num[x] = num[i];
            } else {
                check(num[x], num[i], gate[x]);
            }
        }
    }

    vector<int> de(p + q + r + 1);
    while (!que.empty()) {
        int i = que.front();
        que.pop();
        if (i >= p + q + 1) continue;
        if (gate[i] == 4) num[i] = !num[i];
        
        for (auto x : dir[i]) {
            de[x] = de[i] + 1;
            que.push(x);
            if (num[x] == -1) {
                num[x] = num[i];
            } else {
                check(num[x], num[i], gate[x]);
            }
        }
    }

    int ans = 0;
    for (int i = p + q + 1; i <= p + q + r; i++) {
        ans = max(ans, de[i]);
    }
    cout << ans << '\n';
    for (int i = p + q + 1; i <= p + q + r; i++) {
        cout << num[i] << ' ';
    }
    cout << '\n';
}
