#include <iostream>
#include <vector>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	if (n != k && k != 1) {
		cout << -1 << '\n';
	} else if (n == k) {
		while (n--) cout << 1 << ' ';
		cout << '\n';
	} else {
		for (int i = 1; i <= n; i++) cout << i << ' ';
		cout << '\n';
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
