#include <iostream>
#include <vector>
using namespace std;

const int width = 1000;

int main() {
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);

    int N, K;
    cin >> N >> K;
    vector<vector<int>> v(width + 1, vector<int>(width));

    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        v[x1][y1]++;
        v[x2][y2]++;
        v[x1][y2]--;
        v[x2][y1]--;
    }

    int ans = 0;
    for (int i = 0; i <= width; i++) {
        for (int j = 0; j <= width; j++) {
            if (i > 0) v[i][j] += v[i - 1][j];
            if (j > 0) v[i][j] += v[i][j - 1];
            if (i > 0 && j > 0) v[i][j] -= v[i - 1][j - 1];

            ans += (v[i][j] == K);
        }
    }

    cout << ans << '\n';
}
