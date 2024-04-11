// ISCOJ 4455.整理河內塔
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    int ans = 0;
    while (n--) {
        int a;
        cin >> a;
        
        for (auto &i : v) {
            if (a <= i) {
                i = a;
                a = 0;
                break;
            }
        }

        if (a) {
            v.push_back(a);
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
