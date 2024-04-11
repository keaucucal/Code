#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);

    int n;
    cin >> n;
    
    set<int> upper;
    for (int i = 1; i <= 2 * n; i++) upper.insert(i);
    
    vector<int> game(n);
    for (auto &i : game) {
        cin >> i;
        upper.erase(i);
    }

    set<int> lower;
    
    auto it = upper.begin();
    for (int i = 0; i < n / 2; i++) {
        lower.insert(*it);
        it = upper.erase(it);
    }

    int ans = 0;
    for (int i = 0; i < n / 2; i++) {
        auto it = upper.lower_bound(game[i]);
        if (it == upper.end()) upper.erase(upper.begin());
        else {
            upper.erase(it);
            ans++;
        }
    }

    for (int i = n / 2; i < n; i++) {
        auto it = lower.lower_bound(game[i]);
        if (it == lower.begin()) lower.erase(prev(lower.end()));
        else {
            it--;
            lower.erase(it);
            ans++; 
        }
    }

    cout << ans << '\n';
}
