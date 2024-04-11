#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> v;

void DC(int, int, int);

void solve(int N, int X, int Y) {
    v.resize(N + 1, vector<bool>(N + 1, false));
    v[X][Y] = true;
    DC(1, 1, N);
}

void DC(int x, int y, int n) {
    if (n < 2) return;

    int newN = n / 2;
    int nx = x + newN;
    int ny = y + newN;

    int rotate = 0;
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (v[i][j]) {
                if (i >= nx) {
                    if (j >= ny) rotate = 1; // lower right corner
                    else rotate = 2;         // upper right corner
                } else {
                    if (j >= ny) rotate = 3; // lower left corner
                    else rotate = 4;         // upper left corner
                }

                break;
            }
        }
    }

    switch (rotate) {
        case 1:
            nx -= 1, ny -= 1;
            Report(nx, ny, nx + 1, ny, nx, ny + 1);
            v[nx][ny] = v[nx + 1][ny] = v[nx][ny + 1] = true;
            break;
        case 2:
            nx -= 1;
            Report(nx, ny, nx, ny - 1, nx + 1, ny);
            v[nx][ny] = v[nx][ny - 1] = v[nx + 1][ny] = true;
            break;
        case 3:
            ny -= 1;
            Report(nx, ny, nx - 1, ny, nx, ny + 1);
            v[nx][ny] = v[nx - 1][ny] = v[nx][ny + 1] = true;
            break;
        case 4:
            Report(nx, ny, nx, ny - 1, nx - 1, ny);
            v[nx][ny] = v[nx][ny - 1] = v[nx - 1][ny] = true;
            break;
    }

    DC(x, y, newN);
    DC(x + newN, y, newN);
    DC(x, y + newN, newN);
    DC(x + newN, y + newN, newN);
}
