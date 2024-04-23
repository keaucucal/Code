#include <iostream>
#include <vector>
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> v(101);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v[a]++;
	}

	int ans = 0;
	for (int i = 1; i <= 100; i++) {
		ans += v[i] / 3;
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
