#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    vector<int> capacity(3);
    vector<int> milk(3);
    for (int i = 0; i < 3; i++) {
        int c, m;
        cin >> c >> m;
        capacity[i] = c;
        milk[i] = m;
    }

    for (int i = 0; i < 100; i++) {
        int start = i % 3;
        int end = (i + 1) % 3;

        int trans = min(milk[start], capacity[end] - milk[end]);
        milk[start] -= trans;
        milk[end] += trans;
    }

    for (auto i : milk) cout << i << '\n';
}
