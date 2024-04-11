#include <iostream>
#include <vector>
using namespace std;

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	if ((b + c) % 3 > c) cout << -1 << '\n';
	else {
		int t;
		t = ((b + c) % 3 != 0 ? 1 : 0);
		cout << (b + c) / 3 + t + a << '\n';
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
