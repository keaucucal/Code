#include <iostream>
#include <vector>
using namespace std;

void solve() {
	int n;
	cin >> n;

	int a, ind = -1, ans = n;
	cin >> a;
	for (int i = 1; i < n; i++) {
		int t;
		cin >> t;
		if (t != a) {
			ans = min(ans, i - ind - 1);
			ind = i;
		}
	}
	ans = min(ans, n - 1 - ind);

	if (ind == -1) cout << -1 << '\n';
	else cout << ans << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
