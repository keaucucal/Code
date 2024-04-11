#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        m++;

        int sum = 0;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            int l = s.length();

            sum += l;
            reverse(s.begin(), s.end());

            int a = stoi(s);
            s = to_string(a);
            l -= s.length();

            v[i] = l;
        }

        sort(v.rbegin(), v.rend());
        for (int i = 0; i < n; i += 2) sum -= v[i];

        cout << (sum >= m ? "Sasha\n" : "Anna\n");
    }
}
