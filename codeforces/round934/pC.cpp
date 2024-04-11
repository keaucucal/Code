#include <iostream>
#include <vector>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> cnt(n + 1);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		cnt[a]++;
	}

	int mex = 0;
	while (cnt[mex]) mex++;

	int take = 0;
	while (cnt[take] > 1) take++;
	// 其實多個這就好了
	take++;
	while (cnt[take] > 1) take++;
	
	cout << min(mex, take) << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
