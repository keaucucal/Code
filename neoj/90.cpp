#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> boxes(n);
	for (auto &i : boxes) cin >> i;
	multiset<int> ms;
	while (m--) {
		int a;
		cin >> a;
		ms.insert(a);
	}

	int ans = 0;;
	vector<int> inside;
	for (int box : boxes) {
		while (!ms.empty() && box >= *ms.begin()) {
			auto it = prev(ms.upper_bound(box));
			box -= *it;
			inside.push_back(*it);
			ans++;
			
			ms.erase(it);
		}
	}
		
	sort(inside.rbegin(), inside.rend());

	auto cur = ms.begin();
	for (int num : inside) {
		if (cur != ms.end() && *cur < num) ans--;
		else break;

		for (auto it = cur; it != ms.end(); it++) {
			if (*it > num) break;
			num -= *it;
			cur++, ans++;
		}
	}

	cout << ans << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
