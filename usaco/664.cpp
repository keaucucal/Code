#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    
    int n;
    cin >> n;

    vector<int> ans(26);
    while (n--) {
        string a, b;
        cin >> a >> b;
        vector<int> cnt_a(26), cnt_b(26);
        for (char c : a) cnt_a[c - 'a']++;
        for (char c : b) cnt_b[c - 'a']++;

        for (int i = 0; i < 26; i++) {
            ans[i] += max(cnt_a[i], cnt_b[i]);
        }
    }

    for (int i : ans) cout << i << '\n';
}
