#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>
using namespace std;

inline bool east(char c) {
    return c == 'F' || c == 'H' || c == 'X' || c == 'L';
}
inline bool south(char c) {
    return c == 'F' || c == '7' || c == 'I' || c == 'X';
}
inline bool west(char c) {
    return c == 'H' || c == '7' || c == 'X' || c == 'J';
}
inline bool north(char c) {
    return c == 'I' || c == 'X' || c == 'L' || c == 'J';
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (string &s : v) cin >> s;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '0') continue;

            // bfs
            int sum = 0;
            queue<pair<int, int>> q;
            q.push({i, j});
            while (!q.empty()) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                if (v[x][y] == '0') continue;
                
                if (y < m - 1 && east(v[x][y]) && west(v[x][y + 1])) q.push({x, y + 1});
                if (x < n - 1 && south(v[x][y]) && north(v[x + 1][y])) q.push({x + 1, y});
                if (y > 0 && west(v[x][y]) && east(v[x][y - 1])) q.push({x, y - 1});
                if (x > 0 && north(v[x][y]) && south(v[x - 1][y])) q.push({x - 1, y});
                
                v[x][y] = '0';
                ans = max(ans, ++sum);
            }   
        }
    }

    cout << ans << '\n';
}
