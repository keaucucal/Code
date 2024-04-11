#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

#define SIZE 1010
const vector<int> mx = {-1, 1, 0, 0},
                  my = {0, 0, -1, 1};
const string mc = "UDLR";
vector<vector<char>> maze(SIZE, vector<char>(SIZE));
vector<vector<bool>> vis(SIZE, vector<bool>(SIZE));
vector<vector<int>> path(SIZE, vector<int>(SIZE));

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int ex, ey;
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'A') q.push({i, j});
            else if (maze[i][j] == 'B') ex = i, ey = j;
        }
    }

    maze[ex][ey] = '.';

    while (!q.empty()) {
        auto a = q.front();
        int x = a.first, y = a.second;
        //    cout << x << ' ' << y << '\n';
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + mx[i], ny = y + my[i];
            if (maze[nx][ny] != '.' || vis[nx][ny]) continue;
            
            vis[nx][ny] = true;
            path[nx][ny] = i;
            q.push({nx, ny});
        }
    }

    if (vis[ex][ey]) {
        cout << "YES\n";
        string s;
        while (maze[ex][ey] != 'A') {
            int i = path[ex][ey];
            s += mc[i];
            ex -= mx[i], ey -= my[i]; 
        }
        reverse(s.begin(), s.end());

        cout << s.length() << '\n' << s << '\n';
    } else {
        cout << "NO\n";
    }
}
