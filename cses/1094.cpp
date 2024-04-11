#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    long long ans = 0;

    int a;
    cin >> a;
    n--;
    while (n--) {
        int tmp;
        cin >> tmp;
        if (tmp < a) {
            ans += a - tmp;
        } else {
            a = tmp;
        }
    }

    cout << ans << '\n';

    return 0;
}
