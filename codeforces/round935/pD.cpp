#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define int long long

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> b(n);
	for (auto &i : a) cin >> i;
	for (auto &i : b) cin >> i;

	int ans = 0;
	for (int i = n - 1; i >= m; i--) {
		ans += min(a[i], b[i]);
	}

	int mini = INT_MAX, sum = 0;
	for (int i = m - 1; i >= 0; i--) {
		mini = min(mini, a[i] + sum);
		sum += b[i];
	}

	cout << ans + mini << '\n';
}

signed main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
