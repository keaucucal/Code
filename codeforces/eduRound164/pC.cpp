#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void solve() {
	string x, y;
	cin >> x >> y;

	int n = x.length();
	int i = 0;
	while (i < n && x[i] == y[i]) i++;
	if (i == n) {
		cout << x << '\n' << y << '\n';
		return;
	}

	if (x[i] < y[i]) swap(x[i], y[i]);
	i++;
	while (i < n) {
		if (x[i] > y[i]) swap(x[i], y[i]);
		i++;
	}
		
	cout << x << '\n' << y << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
