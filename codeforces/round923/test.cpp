#include <iostream>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define debug(x) cerr << '\n' << (#x) << " is " << (x) << '\n';
// #define cerr if(false) cerr
#define FILE_IO \
if(fopen("input.txt", "r"))\
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    FILE_IO;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int i, j;
        for(i = 0; s[i] != 'B' && i < n; i++);
        for(j = n; s[j] != 'B' && j >= 0; j--);
        cout << (j - i) + 1 << '\n';
    }
}
