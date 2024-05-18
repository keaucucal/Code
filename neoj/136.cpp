// Meet in the middle
// #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

/*
template<class T>
void Report(T x) {
	cout << x << ' ';
}
*/

bool cmp(const pair<ll, int> &a, const pair<ll, int> &b) {
	return a.first < b.first;
}

void solve(int n, ll k, ll v[]) {
	auto divide = [&](int l, int r) -> vector<pair<ll, int>> {
		int len = r - l + 1;
		vector<pair<ll, int>> ret(1 << len);

		for (int i = 0; i < (1 << len); i++) {
			ll sum = 0;
			for (int j = 0; j < len; j++) {
				if (i & (1 << j)) {
					sum += v[l + j];
				}
			}
			
			ret[i] = make_pair(sum, i);
		}

		return ret;
	};

	vector<pair<ll, int>> left = divide(0, n / 2 - 1);
	vector<pair<ll, int>> right = divide(n / 2, n - 1);
	sort(left.begin(), left.end());
	sort(right.begin(), right.end());

	for (int i = 0; i < left.size(); i++) {
		auto it = lower_bound(right.begin(), right.end(), make_pair(k - left[i].first, 0), cmp);
		int j = it - right.begin();
		if (left[i].first + right[j].first != k) continue;

		// found
		i = left[i].second, j = right[j].second;
		for (int t = 0; (1 << t) <= i; t++) {
			if (i & (1 << t)) {
				Report(t + 1);
			}
		}
		for (int t = 0; (1 << t) <= j; t++) {
			if (j & (1 << t)) {
				Report(t + n / 2 + 1);
			}
		}

		break;	
	}

	Report(-1);
}

/*
int main() {
	int n, k;
	cin >> n >> k;
	ll arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	solve(n, k, arr);
}
*/
