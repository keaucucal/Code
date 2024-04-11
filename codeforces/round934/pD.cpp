#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define int long long

void solve() {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	
	while (q--) {
		int l, r;
		cin >> l >> r;
		int len = r - l + 1;
		string sub = s.substr(l - 1, len);
		string sub2 = sub;
		reverse(sub.begin(), sub.end());
		
		if (sub == sub2) len--;
		int ret = (2 + len) * (len - 1) / 2;
		cout << ret << '\n';
	}
}

signed main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
