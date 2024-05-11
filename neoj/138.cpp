#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5;
const int mod = 1e6 + 7;

int main() {
	vector<int> v(N + 1); 
	v[0] = 1, v[2] = 3;
	for (int i = 4; i <= N; i++) {
		v[i] = (v[i - 2] * 4 - v[i - 4] + mod) % mod;
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << v[n] << '\n';
	}
}
