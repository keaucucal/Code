#include <iostream>
using namespace std;
using ll = long long;

void solve() {
	ll a, b, m;
	cin >> a >> b >> m;
	
	cout <<  (a + m) / a + (b + m) / b << '\n';
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
