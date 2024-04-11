// NEOJ No.62: 數獨
#include <iostream>
#include <vector>
using namespace std;

int cb(int x, int y) {
    return (x / 3) * 3 + (y / 3);
}

vector<vector<int>> sudoku(9, vector<int>(9, 0));
vector<vector<bool>> usb(9, vector<bool>(10, false)),
                     usx(9, vector<bool>(10, false)),
                     usy(9, vector<bool>(10, false));

bool flag;
void solve(int cur) {
    if(flag) return;

    if(cur == 81) {
        for(const auto &i : sudoku) {
            for(const auto &j : i) {
                cout << j;
            }
        }
        cout << '\n';
        flag = true;
        return;
    }

    int x = cur / 9, y = cur % 9;

    if(sudoku[x][y]) {
        solve(cur + 1);
        return;
    }

    int b = cb(x, y);
    for(int i = 1; i <= 9; i++) {
        if(usb[b][i] || usx[x][i] || usy[y][i]) continue;

        usb[b][i] = usx[x][i] = usy[y][i] = true;
        sudoku[x][y] = i;

        solve(cur + 1);

        usb[b][i] = usx[x][i] = usy[y][i] = false;
        sudoku[x][y] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T--) { 
        sudoku.assign(9, vector<int>(9, 0));
        usb.assign(9, vector<bool>(10, false));
        usx.assign(9, vector<bool>(10, false));
        usy.assign(9, vector<bool>(10, false));
        flag = false;

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                char c;
                int tmp;
                cin >> c;
                tmp = c - '0';
                if(c == '.') tmp = 0;
                if(usb[cb(i, j)][tmp] || usx[i][tmp] || usy[j][tmp]) {
                    cout << "No solution.\n";
                    flag = true;
                }
                if(tmp) usb[cb(i, j)][tmp] = usx[i][tmp] = usy[j][tmp] = true;

                sudoku[i][j] = tmp;
            }
        }

        solve(0);
        if(!flag) cout << "No solution.\n";
    }

    return 0;
}
