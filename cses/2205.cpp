#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> v;
    v.push_back("");
    for (int i = 0; i < n; i++) {
        for (int j = v.size() - 1; j >= 0; j--) {
            v.push_back(v[j]);
        }
        for (int j = 0; j < v.size(); j++) {
            v[j] += (j < v.size() / 2 ? '0' : '1');
        }
    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << '\n';
    }

    return 0;
}
