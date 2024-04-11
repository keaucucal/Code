// Binary search the answer (the minimum time)
// on each search, check if all friend can meet
// true -> enough time (decrease r) / false -> need more time (increase l)
#include <iostream>
#include <vector>
#include <functional>
#include <iomanip>
using namespace std;

double bs(double l, double r, function<bool(double)> check) {
    while (r - l > 1e-7) { // the answer is found if l == r in 1e-6
        double mid = l + (r - l) / 2;
        if (check(mid)) { // enough time
            r = mid;         
        } else { // need more time
            l = mid;
        }
    }

    return l;
}

int main() {
    int n;
    cin >> n;

    vector<double> x(n), v(n);
    for (auto &i : x) cin >> i;
    for (auto &i : v) cin >> i;

    cout << fixed << setprecision(12) << bs(0, 1e9, [&](double time) {
        double left = x[0] - v[0] * time, right = x[0] + v[0] * time;
        for (int i = 1; i < n; i++) {
            // the rightmost position if a friend walk left
            left = max(left, x[i] - v[i] * time);
            // the leftmost position if a friend walk right
            right = min(right, x[i] + v[i] * time);
        }

        return (right >= left);
    }) << '\n';
}
