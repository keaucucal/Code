#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    sort(arr.begin(), arr.end(), [](int a, int b) {
        return a > b;
    });

    int sum, ans = 0;
    for (int i = 0, j = n - 1; i <= j; i++) {
        sum = arr[i];
        if (sum + arr[j] <= x) j--;
        ans++;
    }

    cout << ans << '\n';

    return 0;
}
