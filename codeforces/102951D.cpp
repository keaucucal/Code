#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#include <algorithm>
using namespace std;
 
vector<int> indices;
int get_index(int n) {
    return lower_bound(indices.begin(), indices.end(), n) - indices.begin();
}
 
int main() {
    int n, q;
    cin >> n >> q;
 
    vector<tuple<int, int, int>> updates(n);
    for (int i = 0; i < n; i++) {
        int l, r, v;
        cin >> l >> r >> v;
        indices.push_back(l);
        indices.push_back(r);
        updates[i] = {l, r, v};
    }
 
    vector<pair<int, int>> query(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        indices.push_back(l);
        indices.push_back(r);
        query[i] = {l, r};
    }
 
    sort(indices.begin(), indices.end());
    indices.erase(unique(indices.begin(), indices.end()), indices.end());
 
    // update
    n = indices.size();
    vector<long long> arr(n);
    for (const auto &a : updates) {
        int l, r, v;
        tie(l, r, v) = a;
 
        arr[get_index(l)] += v;
        arr[get_index(r)] -= v;
    }
 
    for (int i = 1; i < n; i++) {
        arr[i] += arr[i - 1];
    }
 
    vector<int> width(n);
    for (int i = 1; i < n; i++) {
        width[i] = indices[i] - indices[i - 1];
    }
 
    vector<long long> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + arr[i - 1] * width[i];
    }
    
    for (const auto &a : query) {
        cout << pref[get_index(a.second)] - pref[get_index(a.first)] << '\n';
    }
}
