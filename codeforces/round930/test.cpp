#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int a;
    vector<int> v;
    while (cin >> a) {
        if (a == -1) break;

        v.push_back(a);
    }

    sort(v.begin(), v.end());

    cout << v[v.size() / 2] << '\n';
}
