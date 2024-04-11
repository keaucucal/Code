#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve() {
	char a, b;
	cin >> a >> b;
	int hour = (a - '0') * 10 + b - '0';

	string s;
	cin >> s;

	if (hour == 0) {
		cout << "12";
		cout << s << " AM\n";
	} else if (hour < 12) {
		if (hour < 10) cout << 0;
		cout << hour << s << " AM\n";
	} else {
		if (hour != 12) hour -= 12;
		if (hour < 10) cout << 0;
		cout << hour << s << " PM\n";
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}
