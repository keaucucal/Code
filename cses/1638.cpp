#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> count(n + 1, vector<int>(n + 1));
    count[0][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c;
            cin >> c;
            if (c == '.') {
                count[i][j] = (count[i - 1][j] + count[i][j - 1]) % mod;
            }
        }
    }

    cout << count[n][n] << '\n';

    return 0; 
}
