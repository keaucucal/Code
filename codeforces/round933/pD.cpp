#include <iostream>
#include <set>
using namespace std;
#define int long long

void solve() {
	int n, m, x;
	cin >> n >> m >> x;

	set<int> s;
	s.insert(x - 1);

	int sum = 0;
	while (m--) {
		int r;
		char c;
		cin >> r >> c;
		switch (c) {
			case '0':
				sum = (sum + r) % n;
				break;
			case '1':
				sum = (sum - r + n) % n;
				break;
			case '?':
				set<int> temp;
				for (auto i : s) {
					int t = (i + sum) % n;
					temp.insert((t + r) % n);
					temp.insert((t - r + n) % n);
				}
				s = temp;
				sum = 0;
				break;
		}
	}

	set<int> ans;
	for (auto i : s) {
		ans.insert((i + sum) % n + 1);
	}

	cout << ans.size() << '\n';
	for (auto i : ans) cout << i << ' ';
	cout << '\n';
}

signed main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
