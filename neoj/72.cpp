#include <iostream>
#include <vector>
#include <functional>
#include <tuple>
#include <iomanip>
using namespace std;

// Ternary Search -> find the smallest ( U )
double ts(double l, double r, function<double(double)> f) {
	while (r - l > 1e-7) {
		double mr = (l + r) / 2;
		double ml = (l + mr) / 2;
		if (f(ml) < f(mr)) {
			r = mr;
		} else {
			l = ml;
		}
	}

	return f(l);
}

void solve() {
	int n;
	cin >> n;
	vector<tuple<double, double, double>> v(n);
	for (auto &i : v) {
		double a, b, c;
		cin >> a >> b >> c;
		i = {a, b, c};
	}

	cout << fixed << setprecision(5) << ts(0, 300, [&](const double t) {
			double s = 0;
			for (int i = 0; i < n; i++) {
				double a, b, c;
				tie(a, b, c) = v[i];

				double f = a * (t - b) * (t - b) + c;
				s = max(s, f);
			}

			return s;
		}) << '\n';
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
