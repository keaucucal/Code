#include <iostream>
#include <numeric>
using namespace std;

void solve() {
	int x;
	cin >> x;
	
	int maxi = 0, ans = 0;
	for (int i = 1; i < x; i++) {
		int t = gcd(i, x) + i;
		if (t > maxi) {
			ans = i;
			maxi = t;
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
