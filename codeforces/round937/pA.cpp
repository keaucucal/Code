#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a < b && b < c) {
		cout << "STAIR\n";
	} else if (a < b && c < b) {
		cout << "PEAK\n";
	} else {
		cout << "NONE\n";
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}
