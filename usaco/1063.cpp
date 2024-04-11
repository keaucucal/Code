#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define f first
#define s second

int cntsum(int x1, int y1, int x2, int y2, const vector<vector<int>> &prefix) {
    return prefix[x2 + 1][y2 + 1] - prefix[x1][y2 + 1] - prefix[x2 + 1][y1] + prefix[x1][y1];
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> v(N);
    for (auto &i : v) cin >> i.first >> i.s;

    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++) v[i].f = i + 1;
    sort(v.begin(), v.end(), [](const auto &a, const auto &b) {
        return a.s < b.s;
    });
    for (int i = 0; i < N; i++) v[i].s = i + 1;

    vector<vector<int>> prefix(N + 1, vector<int>(N + 1));
    for (int i = 0; i < N; i++) {
        prefix[v[i].f][v[i].s] = 1;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            prefix[i][j] += prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            int lx = min(v[i].f, v[j].f) - 1;
            int rx = max(v[i].f, v[j].f) - 1;
            ans += cntsum(0, i, lx, j, prefix) * cntsum(rx, i, N - 1, j, prefix);
        }
    }

    cout << ans + 1 << '\n';
}
