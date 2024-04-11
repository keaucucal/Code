#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool v[9][9];
const int dx[4] = {0, 1, 0, -1},
          dy[4] = {-1, 0, 1, 0};
int op[48];

int solve(const int n, const int x, const int y) {

    if (v[x + 1][y] && v[x - 1][y] && !v[x][y - 1] && !v[x][y + 1]) return 0;
    if (v[x][y + 1] && v[x][y - 1] && !v[x - 1][y] && !v[x + 1][y]) return 0;

    if (x == 1 && y == 7) {
        if (n == 48) return 1;
        return 0;
    }

    if(n == 48) return 0;

    int ans = 0;
    v[x][y] = true;

    if (op[n] != -1) {
        int nx = x + dx[op[n]], ny = y + dy[op[n]];
        if (!v[nx][ny]) ans += solve(n + 1, nx, ny);
        
    } else {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (v[nx][ny]) continue;
            ans += solve(n + 1, nx, ny);
        }
    }

    v[x][y] = false;
    return ans;
}

int main() {
    string s;
    getline(cin, s);
   
    for (int i = 0; i < 48; i++) {
        switch (s[i]) {
            case 'U':
                op[i] = 0;
                break;
            case 'R':
                op[i] = 1;
                break;
            case 'D':
                op[i] = 2;
                break;
            case 'L':
                op[i] = 3;
                break;
            default:
                op[i] = -1;
        }
    }

    for (int i = 0; i < 9; i++) {
        v[i][0] = v[0][i] = v[i][8] = v[8][i] = true;
    }
    for (int i = 1; i <= 7; i++) {
        for (int j = 1; j <= 7; j++) {
            v[i][j] = false;
        }
    }

    cout << solve(0, 1, 1) << '\n';

    return 0;
}
