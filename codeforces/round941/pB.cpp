#include <iostream>
#include <vector>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;

	int top, bot, left, right;
	top = bot = left = right = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char c;
			cin >> c;
			if (c == 'W') continue;

			if (i == 1) top++;
			if (i == n) bot++;
			if (j == 1) left++;
			if (j == m) right++;
		}
	}

	if (top + bot + left + right == 0) {
		cout << "YES\n";
	} else if (top + bot + left + right == n + n + m + m) {
		cout << "YES\n";
	} else if ((top == m || bot == m || left == n || right == n) && (top == 0 || bot == 0 || left == 0 || right == 0)) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
