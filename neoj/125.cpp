// NEOJ NO.125 逆序數對
// merge_sort + 前墜和，注意資料型態
#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int mod = 1e7 + 19;

vector<int> v, sum;
int ans;

void merge_sort(int, int);

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    v.resize(N + 1);
    for (int i = 1; i <= N; i++) cin >> v[i];
    sum.resize(N + 1);

    ans = 0;
    merge_sort(1, N);
    cout << ans << '\n';

    return 0;
}

void merge_sort(int l, int r) {
    if (l == r) return;

    int mid = (l + r) / 2;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);

    sum[l - 1] = 0;
    for (int i = l; i <= mid; i++) sum[i] = sum[i - 1] + v[i];

    int i = l, j = mid + 1;
    vector<int> temp;
    while (i <= mid && j <= r) {
        if (v[j] < v[i]) {
            ans = (ans - sum[i - 1] + sum[mid] + v[j] * (mid - i + 1)) % mod;
            temp.push_back(v[j]);
            j++;
        } else {
            temp.push_back(v[i]);
            i++;
        }
    }
    while (i <= mid) temp.push_back(v[i]), i++;
    while (j <= r) temp.push_back(v[j]), j++;

    for (int k = l; k <= r; k++) v[k] = temp[k - l];

    return;
}
