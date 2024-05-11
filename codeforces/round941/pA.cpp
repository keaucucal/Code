#include <iostream>
#include <vector>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> cnt(101);

	int ans = n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		cnt[a]++;
		if (cnt[a] == k) {
			ans = min(n, k - 1);
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
