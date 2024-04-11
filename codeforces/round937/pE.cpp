#include <iostream>
#include <string>
using namespace std;

void solve() {
	int n;
	string s;
	cin >> n >> s;

	for (int i = 1; i <= n; i++) {
		if (n % i) continue;

		int check = 1;
		for (int j = 0; j < i; j++) {
			for (int k = j + i; k < n; k += i) {
				if (s[k] != s[j]) check--;
			}
		}

		if (check >= 0) {
			cout << i << '\n';
			return;
		}

		check = 1;
		for (int j = n - i; j < n; j++) {
			for (int k = j - i; k >= 0; k -= i) {
				if (s[k] != s[j]) check--;
			}
		}

		if (check >= 0) {
			cout << i << '\n';
			return;
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
