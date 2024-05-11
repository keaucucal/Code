#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << 1 << ' ' << 1 << '\n';
		cout << 1 << ' ' << 2 << '\n';
		if (n > 2) cout << n << ' ' << n << '\n';
		for (int i = 0; i < n - 3; i++) {
			cout << 3 + i << ' ' << 1 << '\n';
		}
	}
}
