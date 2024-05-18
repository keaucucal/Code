#include <iostream>
using namespace std;
#define int long long

struct pt {
	int x, y;
};

inline pt operator - (const pt &a, const pt &b) {
	return {a.x - b.x, a.y - b.y};
}

// dot 內積
inline int operator * (const pt &a, const pt &b) {
	return a.x * b.x + a.y * b.y;
}
// cross 外積
inline int operator ^ (const pt &a, const pt &b) {
	return a.x * b.y - a.y * b.x;
}

signed main() {
	int n;
	cin >> n;

	pt a, b;
	cin >> a.x >> a.y >> b.x >> b.y;
	n -= 2;

	int left = 0, right = 0, turn = 0;
	while (n--) {
		pt c;
		cin >> c.x >> c.y;

		int cross = (b - a) ^ (c - a);
		int dot = (b - a) * (c - b);

		if (cross > 0) left++;
		else if (cross < 0) right++;
		else if (dot < 0) turn++;

		a = b;
		b = c;
	}

	cout << left << ' ' << right << ' ' << turn << '\n';
}
