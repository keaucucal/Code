#include <iostream>
#include <string>
using namespace std;

string s;

int cnt(string check) {
	int ret = 0;
	size_t pos = s.find(check);
	while (pos != string::npos) {
		ret++;
		pos += check.length();
		pos = s.find(check, pos);
	}

	return ret; 
}


void solve() {
	int n;
	cin >> n >> s;

	cout << cnt("map") + cnt("pie") - cnt("mapie") << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
