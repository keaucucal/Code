#include <iostream>
#include <vector>
#include <string>
using namespace std;

int cnt(int a) {
	return a / 2 + a % 2;
}

void solve() {
	int n;
	string s;
	cin >> n >> s;

	vector<int> pre(n + 1);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += s[i - 1] - '0';
		pre[i] = pre[i - 1] + (s[i - 1] - '0');
	}

	auto check = [&](int index) -> bool {
		// left zeros = index + 1 - pre[index] / right ones = sum - pre[index]
		return (cnt(index) <= index - pre[index] && cnt(n - index) <= sum - pre[index]);
	};

	if (check(n / 2)) {
		cout << n / 2 << '\n';
		return;
	}

	for (int i = 0; i <= n / 2; i++) {
		int l = (n + 1) / 2 - i;
		int r = (n + 1) / 2 + i;

		if (check(l)) {
			cout << l << '\n';
			return;
		} else if (check(r)) {
			cout << r << '\n';
			return;
		}
	}
	
	/*
	for (int i = 0; i <= n; i++) {
		cout << check(i) << ' ';
	}
	*/

	cout << 0 << '\n';
}
		

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
