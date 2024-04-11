#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> v(26);
        while (n--) {
            int a;
            cin >> a;
            
            int ind = find(v.begin(), v.end(), a) - v.begin();
            cout << char('a' + ind);
            v[ind]++;
        }

        cout << '\n';
    }
}
