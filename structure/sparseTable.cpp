#include <iostream>
#include <vector>
#include <cmath> // log2
using namespace std;

#define op min

struct sparseTable {
    vector<vector<int>> st;

    sparseTable(int n, vector<int> v) {
        int k = log2(n);
        st.resize(n, vector<int>(k + 1));

        for (int i = 0; i < n; i++) st[i][0] = v[i];

        for (int j = 1; j <= k; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = op(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int req(int l, int r) {
        l--, r--; // [l, r]
        int k = log2(r - l + 1);
        return op(st[l][k], st[r - (1 << k) + 1][k]);
    }
};

int main() {
    vector<int> v = {3, 3, 5, 2};
    sparseTable st(v.size(), v);

    cout << st.req(2, 3);
}
