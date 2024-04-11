#include <iostream>
#include <vector>
using namespace std;
 
int req(int a, int b, const vector<int> &tree, int m) {
    int ans = 1;
    while (a <= b) {
        if (a & 1) ans = ans * tree[a++] % m;
        if (!(b & 1)) ans = ans * tree[b--] % m;
        a >>= 1, b >>= 1; 
    }
 
    return ans;
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> tree(2 * n);
    for (int i = n; i < 2 * n; i++) {
        cin >> tree[i];
        tree[i] %= m;
    }
 
    for (int i = n - 1; i >= 1; i--) {
        tree[i] = tree[i * 2] * tree[i * 2 + 1] % m;
    }
 
    string s;
    cin >> s;
    
    int l = n, r = 2 * n - 1;
    for (int i = 0; i < n; i++) {
        cout << req(l, r, tree, m) << ' ';
        if (s[i] == 'L') l++;
        else r--;
    }
 
    cout << '\n';
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
