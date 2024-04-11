#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    
    vector<int> limit(101);
    int pos = 1;
    while (n--) {
        int seg, l;
        cin >> seg >> l;
        while (seg--) {
            limit[pos++] = l;
        }
    }

    pos = 1;
    int ans = 0;
    while (m--) {
        int seg, speed;
        cin >> seg >> speed;
        while (seg--) {
            if (speed > limit[pos]) {
                ans = max(ans, speed - limit[pos]);
            }
            pos++;
        }
    }

    cout << ans << '\n';
}
