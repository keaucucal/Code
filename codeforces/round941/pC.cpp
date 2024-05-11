#include <iostream>
#include <set>
using namespace std;

void solve() {
	int n;
	cin >> n;

	bool flag = true;
	int pre = 0;
	while (n--) {
		int a;
		cin >> a;
		if (n <= 1) continue;

		a -= pre;
		if (a == 1) {
			flag = !flag;
		} else {
			flag = true;
		}

		pre = a;
	}

	cout << (flag ? "Alice" : "Bob") << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
