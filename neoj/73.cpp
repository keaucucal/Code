#include <iostream>
#include <vector>
#include <functional>
using namespace std;

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
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (auto &i : v) cin >> i;

	cout << bs(0, 1e9, [&](const int &x) {
			int block = 0, cur = 0;
			for (int i = 0; i < n; i++) {
				if (v[i] > x) return false;
				if (cur + v[i] > x) {
					block++;
					cur = 0;
				}
				cur += v[i];
			}
			if (cur) block++;

			return m >= block;
		}) << '\n';
}
	

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
