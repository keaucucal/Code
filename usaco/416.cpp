#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);

    int N, K;
    cin >> N >> K;
    vector<vector<int>> v(2 * N, vector<int>(2 * N));

    int total = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i + j][N - i + j + 1];
            total += v[i + j][N - i + j + 1];
        }
    }

    K = K * 2 + 1;
    int ans = 0;
    for (int i = 1; i < N * 2; i++) {
        for (int j = 1; j < N * 2; j++) {
            v[i][j] += v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
            if (i >= K && j >= K) {
                int temp = v[i][j] - v[i - K][j] - v[i][j - K] + v[i - K][j - K];
                ans = max(ans, temp);
            }
        }
    }

    if (K >= N * 2) ans = total;

    cout << ans << '\n';
}
