#include <iostream>
#include <vector>
#include <utility>
#include <map>
using namespace std;
using ll = long long;

#define x first
#define y second

int main() {
	int n;
	cin >> n;
	vector<pair<ll, ll>> v(n);

	for (auto &a : v) {
		cin >> a.x >> a.y;
	}

	map<ll, int> m;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ll dx = v[i].x - v[j].x, dy = v[i].y - v[j].y;
			ans += m[dx * dx + dy * dy];

			m[dx * dx + dy * dy]++;
		}
	}

	cout << ans << '\n';
}
