#include <iostream>
#include <vector>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<bool> cnt(n + 1);
	int mex = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		/*
		// a = mex(all(p)) - p
		// mex(all(p)) = mex || while (cnt[mex]) mex++
		if (!cnt[mex - a]) { // p == mex(all) - a
			cnt[mex - a]++;
			cout << mex - a << '\n';
		} else {
			while (cnt[mex]) {
				mex++;
				if (!cnt[mex - a]) {
					cnt[mex - a]++;
					break;
				}
			}
		}
		*/
		
		if (a >= 1) {
			cout << mex << ' ';
			mex++;
			while (cnt[mex]) mex++;
		} else if (a < 0) {
			cout << mex - a << ' ';
			cnt[mex - a] = true;
			while (cnt[mex]) mex++;
		}
	}
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
		cout << '\n';
	}
}
