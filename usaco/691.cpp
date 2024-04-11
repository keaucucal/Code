#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int N; 
    cin >> N;
    vector<int> H(N + 1), P(N + 1), S(N + 1);
    for (int i = 1; i <= N; i++) {
        char c;
        cin >> c;

        H[i] = H[i - 1];
        P[i] = P[i - 1];
        S[i] = S[i - 1];

        switch (c) {
            case 'H':
                H[i]++;
                break;
            case 'P':
                P[i]++;
                break;
            case 'S':
                S[i]++;
                break;
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int beforeMax = max(max(H[i], P[i]), S[i]);
        int afterMax = max(max(H[N] - H[i], P[N] - P[i]), S[N] - S[i]);
        ans = max(ans, beforeMax + afterMax);
    }

    cout << ans << '\n';
}
