#include <iostream>
using namespace std;
#define int long long

struct pt {
	int x, y;

};

inline pt operator - (const pt &a, const pt &b) {
	return {a.x - b.x, a.y - b.y};
}

inline int operator * (const pt &a, const pt &b) {
	return a.x * b.x + a.y * b.y;
}

inline int operator ^ (const pt &a, const pt &b) {
	return a.x * b.y - a.y * b.x;
}

bool onseg(pt a, pt b, pt o) {
	int cross = (a - o) ^ (b - o);
	int dot = (a - o) * (b - o);
	return (cross == 0) && (dot <= 0);
}

int ori(pt a, pt b, pt o) {
	int cross = (a - o) ^ (b - o);
	if (cross == 0) return 0;
	return cross > 0 ? 1 : -1;
}

bool banana(pt a, pt b, pt c, pt d) {
	if (onseg(a, b, c) || onseg(a, b, d) || onseg(c, d, a) || onseg(c, d, b)) return true;
	return ori(a, b, c) * ori(a, b, d) < 0 && ori(c, d, a) * ori(c, d, b) < 0;
}

void solve() {
	pt a, b, c, d;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;

	cout << (banana(a, b, c, d) ? "Yes" : "No") << '\n';	
}

signed main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
