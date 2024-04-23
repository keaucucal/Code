#include <iostream>
#include <cmath>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;

	if (n == 1) {
		cout << k << '\n';
		return;
	}

	int ans = pow(2, (int)log2(k)) - 1;
	cout << ans << ' ' << k - ans;
	for (int i = 0; i < n - 2; i++) cout << ' ' << 0;
	cout << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
