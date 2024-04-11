// NEOJ 74.円円攻略黃河
// greedy
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        
        vector<int> v(N);
        for (auto &i : v) cin >> i;

        bool flag = false; // false->down / true->up
        int ans = 1;
        int i = 1;
        while (i < N && v[i - 1] <= v[i]) i++;

        while (i < N) {
            if (flag) { // go up
                while (i < N && v[i - 1] <= v[i]) i++; 
                ans += 2;
                flag = false;
            } else { // go down
                while (i < N && v[i - 1] >= v[i]) i++;
                flag = true;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
