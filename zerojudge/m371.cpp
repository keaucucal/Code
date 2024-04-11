#include <iostream>
#include <vector>
using namespace std;

const int x[4] = {-1, 1, 0, 0};
const int y[4] = {0, 0, -1, 1};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n + 2, vector<int>(m + 2));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
            v[i][j]++;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k < 4; k++) {
                int X = i + x[k], Y = j + y[k];
                while (v[X][Y] == -1) X += x[k], Y += y[k];

                if (v[i][j] == v[X][Y]) {
                    ans += v[i][j] - 1;
                    v[i][j] = v[X][Y] = -1;
                    break;
                }
            }
        }
    }

    cout << ans << '\n';
}
