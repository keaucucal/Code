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

	int ans = x + y * 2 - 2;
	vector<int> gap;
	for (int i = 1; i < x; i++) {
		if ((v[i] - v[i - 1]) % 2 == 0) gap.push_back(v[i] - v[i - 1]);
	}

	if ((v[0] + n - v[x - 1]) % 2 == 0) gap.push_back(v[0] + n - v[x - 1]);

	sort(gap.begin(), gap.end());
	for (int v : gap) {
		int need = v / 2 - 1;
		if (y >= need) {
			y -= need;
			ans++;
		}
	}

	cout << min(n - 2, ans) << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
