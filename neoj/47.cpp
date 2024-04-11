#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	set<int> st;
	while (n--) {
		string s;
		int a;
		cin >> s >> a;
		switch (s[0]) {
			case 'i':
				st.insert(a);
				break;
			case 'd':
				st.erase(a);
				break;
			case 'q':
				auto it = st.lower_bound(a);
				if (it == st.begin()) {
					cout << *it << '\n';
					break;
				}
				if (it == st.end()) {
					cout << *(--it) << '\n';
					break;
				}

				auto it2 = it;
				it2--;

				if (*it - a == a - *it2) {
					cout << *it2 << ' ' << *it << '\n';
				} else if (*it - a < a - *it2) {
					cout << *it << '\n';
				} else {
					cout << *it2 << '\n';
				}
				break;
		}
	}
}
				


