#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if ((i | (n - 1 - i)) == n - 1) cout << i << ' ';
    }

    cout << ans << '\n';

    return 0;
}
