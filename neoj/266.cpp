#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	map<string, int> mp;

	while (n--) {
		string s;
		cin >> s;
		mp[s]++;
	}

	while (m--) {
		string s;
		cin >> s;
		cout << mp[s] << '\n';
	}
}
