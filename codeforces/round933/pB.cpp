#include <iostream>
#include <vector>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &i : v) cin >> i;

	for (int i = 0; i < n - 2; i++) {
		if (v[i] < 0) {
			cout << "NO\n";
			return;
		}

		v[i + 1] -= v[i] * 2;
		v[i + 2] -= v[i];
	}

	if (v[n - 2] == 0 && v[n - 1] == 0) cout << "YES\n";
 	else cout << "NO\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
