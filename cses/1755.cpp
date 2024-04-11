#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v(26);
    
    char c;
    int n = 0;
    while (cin >> c) {
        v[c - 'A']++;
        n++;
    }

    string s = "";
    int flag = -1;
    for (int i = 0; i < 26; i++) {
        if (v[i] % 2 == 0) {
            for (int j = 0; j < v[i]; j += 2) {
                s += ('A' + i);
            }
        } else {
            if (flag != -1 || n % 2 == 0) {
                cout << "NO SOLUTION\n";
                return 0;
            }
            flag = i;
        }
    }

    cout << s;
    if (flag != -1) {
        for (int i = 0; i < v[flag]; i++) {
            cout << char('A' + flag);
        }
    }
    reverse(s.begin(), s.end());
    cout << s << '\n';

    return 0;
}
