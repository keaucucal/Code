#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    while(cin >> n) {
        vector<int> v(n);

        for (int &i : v) cin >> i;
        sort(v.begin(), v.end());

        for (const int &i : v) cout << i << ' ';
        cout << '\n';
    }
    
    return 0;
}
