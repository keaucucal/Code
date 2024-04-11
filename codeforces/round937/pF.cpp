#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void solve() {
	int a, b, c;
	cin >> a >> b >> c;

	if (c != a + 1) {
		cout << -1 << '\n';
		return;
	}

	if (a == 0) {
		cout << b << '\n';
		return;
	}
	
	int n = log2(a + 1);
	a -= pow(2, n) - 1;
	if (a > 0)
		b -= pow(2, n) - a;


	if (b > 0) {
		int t = pow(2, n) + a;
		n++;
		n += (b - 1) / t;
	}

	if (a > 0) n++;

	cout << n << '\n';
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}
