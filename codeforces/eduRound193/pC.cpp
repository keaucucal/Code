#include <iostream>
#include <string>
using namespace std;

void solve() {
	int n;
	cin >> n;
	string s, s2;
	cin >> s >> s2;

	for (int i = 2; i < n; i += 2) {
		if (s2[i] == '<' && (s[i - 1] == '<' || s[i + 1] == '<')) {
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
