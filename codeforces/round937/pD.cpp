#include <iostream>
#include <vector>
#include <bitset>
#include <string>
using namespace std;

vector<int> v(32);

void solve() {
	int n;
	cin >> n;

	for (int i = 31; i >= 2; i--) {
		while (n % v[i] == 0) {
			n /= v[i];
		}
	}

	cout << (n == 1 ? "YES" : "NO") << '\n';
}

int main() {
	for (int i = 0; i < 32; i++) {
		bitset<5> binary(i);
		string s = binary.to_string();
		v[i] = stoi(s);
	}

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}
