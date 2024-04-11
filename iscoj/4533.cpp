// 雙指針 ISCOJ 4533
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &i : a) cin >> i;
    
    ll sum = 0, left = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        while(sum > k) {
            sum -= a[left];
            left ++;
        }
        if(sum <= k) {
            ans += i - left + 1;
        }
    }

    cout << ans << '\n';

    return 0;
}
