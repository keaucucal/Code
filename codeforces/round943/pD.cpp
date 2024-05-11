#include <iostream>
#include <vector>
using namespace std;
#define int long long

void solve() {
	int n, k, b, s;
	cin >> n >> k >> b >> s;
	
	vector<int> p(n + 1), a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int cur = 0;
	int B = 0;
	n = min(n, k);
	for (int i = 0; i < n; i++) {
		B = max(B, cur + a[b] * (k - i));
		cur += a[b];
		b = p[b];
	}

	cur = 0;
	int A = 0;
	for (int i = 0; i < n; i++) {
		A = max(A, cur + a[s] * (k - i));
		cur += a[s];
		s = p[s];
	}

	if (A == B) cout << "Draw\n";
	else cout << (A > B ? "Sasha\n" : "Bodya\n");
}

signed main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
