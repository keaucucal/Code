#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
	int n, x, y;
	cin >> n >> x >> y;
	vector<int> v(x);
	for (auto &i : v) cin >> i;
	sort(v.begin(), v.end());

	long long ans = x - 2;
	for (int i = 1; i < x; i++) {
		if (v[i] - v[i - 1] == 2) ans++;
	}

	if (v[0] + n - v[x - 1] == 2) ans++;

	cout << ans << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
