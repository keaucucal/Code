#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
#define int long long

int bs(int l, int r, function<bool(int)> check) {
	while (l < r) {
		int mid = l + (r - l) / 2;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}

	return l;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n), b(n), c(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	for (auto &i : c) cin >> i;
	sort(c.begin(), c.end());

	int ans = bs(0, 1e9, [&](const int x) {
			vector<int> temp(n);
			for (int i = 0; i < n; i++) {
				temp[i] = a[i] + b[i] * x;
			}

			int wins = 0;
			sort(temp.begin(), temp.end());
			for (int i = 0; i < n; i++) {
				if (temp[i] > c[wins]) wins++;
			}
	
			return wins >= k;
		});

	if (ans == 1e9) {
		cout << -1 << '\n';
	} else {
		cout << ans << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
