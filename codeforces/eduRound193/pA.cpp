#include <iostream>
#include <vector>
using namespace std;

void solve() {
	int n;
	cin >> n;
	if (n & 1) cout << "NO\n";
	else {
		cout << "YES\n";
		while (n) {
			cout << "AAB";
			n -= 2;
		}
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
