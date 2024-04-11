#include <iostream>
#include <vector>
using namespace std;
#define SIZE 1010

const vector<int> mx = {-1, 1, 0, 0};
const vector<int> my = {0, 0, -1, 1};
vector<vector<bool>> v(SIZE, vector<bool>(SIZE)),
                     vis(SIZE, vector<bool>(SIZE));

void DFS(int x, int y) {
    vis[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + mx[i];
        int ny = y + my[i];
        if (!v[nx][ny] || vis[nx][ny]) continue;

        DFS(nx, ny);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            if (c == '.') v[i][j] = true;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!v[i][j] || vis[i][j]) continue;

            DFS(i, j);
            ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}
