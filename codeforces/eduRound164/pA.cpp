#include <iostream>
using namespace std;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	if (k >= (n / m * (m - 1) + max(n % m - 1, 0))) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
