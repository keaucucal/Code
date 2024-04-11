#include <iostream>
#include <climits>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

void solve() {
	int n, k;
	cin >> n >> k;

	int total = 0;
	int maxi = LLONG_MIN, sum = 0;
	while (n--) {
		int a;
		cin >> a;
		total = (total + a) % mod;
		sum = max(a, sum + a);
		maxi = max(maxi, sum);
	}

	if (maxi <= 0) {
		while (total < 0) total += mod;
		cout << total << '\n';
		return;
	}

	total -= maxi;
	while (k--) {
		maxi = maxi * 2 % mod;
	}

	total += maxi;
	while (total < 0) total += mod;
	cout << total << '\n';
}

signed main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
