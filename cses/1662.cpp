#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> v(n);

    v[0] = 1;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        sum = (sum + a) % n;
        sum = (sum + n) % n;
        v[sum]++;
    }

    long long ans = 0;
    for (long long x : v) {
        ans += x * (x - 1) / 2;
    }

    cout << ans << '\n';
}
