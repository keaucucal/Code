#include <iostream>
#include <vector>
using namespace std;

const int mod = 2019;
vector<int> v(mod);

int main() {
    string s;
    cin >> s;
    int n = s.length();
    
    v[0] = 1;
    int ans = 0, tens = 1, cur = 0;
    for (int i = n - 1; i >= 0; i--) {
        cur = (cur + (s[i] - '0') * tens) % mod;
        ans += v[cur];
        v[cur]++;
        tens = tens * 10 % mod;
    }

    cout << ans << '\n';
}
