#include <iostream>
#include <map>
#include <string>
using namespace std;
#define int long long

signed main() {
	string s;
	cin >> s;

	int cur = 0;
	map<int, int> m;
	m[cur]++;

	for (char c : s) {
		int t = c - '0';
		cur ^= 1 << t;
		m[cur]++;
	}

	long long ans = 0;
	for (auto [_, a] : m) {
		ans += a * (a - 1) / 2;
	}

	cout << ans << '\n';
}
