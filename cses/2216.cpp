#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<bool> v(n + 1);

    int ans = 0;
    while (n--) {
        int x;
        cin >> x;
        ans += !(v[x - 1]);
        v[x] = true;
    }

    cout << ans << '\n';
}
