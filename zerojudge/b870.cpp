#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N, K;
vector<int> v;

inline bool isPossible(const int x) {
    int cnt = 0;
    int range = 0;
    int i = 0;
    while (i < N) {
        range = v[i] + 2 * x;
        cnt++;
        if (cnt > K) return false;
        while (i < N && v[i] <= range) i++;
    }
    
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        v.resize(N);
        for (int &x : v) cin >> x;

        sort(v.begin(), v.end());

        int l = 0, r = 1e9;
        while (l < r) {
            int mid = (l + r) / 2;
            if (isPossible(mid)) r = mid;
            else l = mid + 1;
        }

        cout << r << '\n';
    }

    return 0;
}
