#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> v(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            v[i][j] = v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
            char c;
            cin >> c;
            if (c == '*') v[i][j]++; 
        }
    }

    while (q--) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << (v[y2][x2] - v[y2][x1 - 1] - v[y1 - 1][x2] + v[y1 - 1][x1 - 1]) << '\n';
    }
}
