#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
typedef long long ll;
 
int main() {
    int n;
    cin >> n;
 
    ll ans = LLONG_MIN, sum = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        sum = max(x, sum + x);
        ans = max(ans, sum);
    }
    
    cout << ans << '\n';
 
    return 0;
}
