#include <iostream>
#include <vector>
using namespace std;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	vector<int> b(m);
	for (auto &i : a) cin >> i;
	for (auto &i : b) cin >> i;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i] + b[j] <= k) ans++;
		}
	}

	cout << ans << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
