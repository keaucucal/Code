#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

const ll A = 69420;
const ll B = 1e9 + 7;

int main() {
	string s;
	cin >> s;
	int n = s.length();

	vector<ll> power(n, 1);
	for (int i = 1; i < n; i++) {
		power[i] = power[i - 1] * A % B;
	}

	vector<ll> prefix(n + 1);
	for (int i = 1; i <= n; i++) {
		prefix[i] = (prefix[i - 1] * A + s[i - 1]) % B;
	}

	auto getHash = [&](int l, int r) -> ll {
		return (prefix[r + 1] - (power[r - l + 1] * prefix[l] % B) + B) % B;
	};

	for (int i = 1; i <= n; i++) {
		int cur = 0;
		bool ok = true;
		while (cur < n) {
			int len = min(i, n - cur);
			ok &= getHash(0, len - 1) == getHash(cur, cur + len - 1);
			
			cur += len;
		}

		if (ok) cout << i << '\n';
	}
}
