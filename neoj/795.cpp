#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

using ll = long long;
#define x first
#define y second

ll dist(pair<ll, ll> a, pair<ll, ll> b) {
	ll X = a.x - b.x, Y = a.y - b.y;
	return X * X + Y * Y;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<ll, ll>> v(n);
	for (auto &a : v) cin >> a.x >> a.y;
	sort(v.begin(), v.end());

	set<pair<ll, ll>> s;
	s.insert({v[0].y, v[0].x});
	
	ll l = 0, ans = LLONG_MAX;
	for (int i = 1; i < n; i++) {
		double d = ceil(sqrt(ans));
		while (l < i && v[l].x < v[i].x - d) {
			s.erase({v[l].y, v[l].x});
			l++;
		}

		auto it = s.lower_bound({v[i].y - d, 0});
		auto it2 = s.upper_bound({v[i].y + d, 0});
		for (auto it3 = it; it3 != it2; it3++) {
			ans = min(ans, dist({it3->y, it3->x}, v[i]));
		}
		s.insert({v[i].y, v[i].x});
	}

	cout << ans << '\n';
}
