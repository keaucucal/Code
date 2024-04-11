#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 2);
    v[n + 1] = n + 1;
    vector<int> arr(n + 1);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        ans += !(v[x - 1]);
        v[x] = i;
        arr[i] = x;
    }

    while (m--) {
        int a, b;
        cin >> a >> b;
        int x = arr[a], y = arr[b];
        swap(arr[a], arr[b]);

        if (a >= v[x - 1] && b < v[x - 1]) ans++;
        if (a < v[x - 1] && b >= v[x - 1]) ans--;
        if (a <= v[x + 1] && b > v[x + 1]) ans++;
        if (a > v[x + 1] && b <= v[x + 1]) ans--;
        v[x] = b;

        if (b >= v[y - 1] && a < v[y - 1]) ans++;
        if (b < v[y - 1] && a >= v[y - 1]) ans--;
        if (b <= v[y + 1] && a > v[y + 1]) ans++;
        if (b > v[y + 1] && a <= v[y + 1]) ans--;

        v[y] = a;
        cout << ans << '\n';
    }
}
