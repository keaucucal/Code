#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> v = {0, 1, 2, 3};
    vector<int> ans(4);
    while (n--) {
        int a, b, g;
        cin >> a >> b >> g;
        swap(v[a], v[b]);
        ans[v[g]]++;
    }

    cout << max({ans[1], ans[2], ans[3]}) << '\n';
}
