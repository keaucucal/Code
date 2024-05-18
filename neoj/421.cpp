#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> v;
	while (n--) {
		int a;
		cin >> a;
		if (a * 2 >= m) {
			auto it = upper_bound(v.begin(), v.end(), a * 2);
			if (it == v.end()) v.push_back(a * 2);
			else *it = a * 2;
		} 
		if (a >= m) {
			auto it = upper_bound(v.begin(), v.end(), a);
			if (it == v.end()) v.push_back(a);
			else *it = a;
		}
	}

	cout << v.size() << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
