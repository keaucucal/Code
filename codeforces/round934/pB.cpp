#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	k *= 2;
	vector<int> cnt(n + 1), left, right, both;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		cnt[a]++;
	}

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		// do nothing

		if (cnt[i] == 0) right.push_back(i);
		if (cnt[i] == 1) both.push_back(i);
		if (cnt[i] == 2) left.push_back(i);
	}

	vector<int> ans1, ans2;
	while (k >= 2) {
		if (!right.empty()) {
			ans2.push_back(right.back());
			ans2.push_back(right.back());
			ans1.push_back(left.back());
			ans1.push_back(left.back());
			right.pop_back();
			left.pop_back();
			k -= 2;
		} else break;
	}

	while (k) {
		ans1.push_back(both.back());
		ans2.push_back(both.back());
		both.pop_back();
		k--;
	}

	for (auto i : ans1) cout << i << ' ';
	cout << '\n';
	for (auto i : ans2) cout << i << ' ';
	cout << '\n';
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
