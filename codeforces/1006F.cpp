#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long ll;

int n, m;
ll k;
vector<vector<ll>> v;
vector<vector<unordered_map<ll, int>>> ump;

int N;
void FirstHalfDFS(const int &i, const int &j, ll sum) {
    sum ^= v[i][j];
    if (i + j == (n + m + 1) / 2) {
        ump[i][j][sum ^ k]++;
        return;
    }

    if (i < n) FirstHalfDFS(i + 1, j, sum);
    if (j < m) FirstHalfDFS(i, j + 1, sum);
}

ll ans = 0;
void SecondHalfDFS(const int &i, const int &j, ll sum) {
    if (i + j == (n + m + 1) / 2) {
        ans += ump[i][j][sum];
        return;
    }
    sum ^= v[i][j];

    if (i > 0) SecondHalfDFS(i - 1, j, sum);
    if (j > 0) SecondHalfDFS(i, j - 1, sum);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    v.resize(n, vector<ll>(m));
    ump.resize(n, vector<unordered_map<ll, int>>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    m -= 1;
    n -= 1;
    FirstHalfDFS(0, 0, 0);
    SecondHalfDFS(n, m, 0);

    cout << ans << '\n';

    return 0;
}
