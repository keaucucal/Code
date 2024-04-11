#include <bits/stdc++.h>
#define pii pair<int, int>
#define int long long
#define ff first
#define ss second
using namespace std;

vector<int> manacher(const string& s) {
    string T = "#";
    for (char c : s) {
        T += c;
        T += "#";
    }
    int n = T.size();
    vector<int> P(n, 0);
    int C = 0, R = 0;
    for (int i = 1; i < n - 1; ++i) {
        int mirr = 2 * C - i;
        if (i < R)
            P[i] = min(R - i, P[mirr]);
        while (T[i + (1 + P[i])] == T[i - (1 + P[i])])
            P[i]++;
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }
    return P;
}

// 查询函数
bool is_palindrome(const vector<int>& P, int start, int end) {
    // 预处理后字符串的索引
    int n = P.size();
    int p_start = start * 2 + 1;
    int p_end = end * 2 + 1;
    int length = end - start + 1;

    // 判断长度为偶数的子串是否为回文
    if (length % 2 == 0) {
        int mid = (p_start + p_end) / 2;
    }
    // 判断长度为奇数的子串是否为回文
    else {
        int mid = (p_start + p_end) / 2;
        return P[mid] >= length / 2 + 1;
    }
}


signed main(){
        ios_base::sync_with_stdio(false);cin.tie(0);
        int t;cin>>t;
        vector<int> ans(200007, 0);
        for(int i=2; i<200007; i++){
                ans[i]=ans[i-1]+i;
        }
        while(t--){
                int n, q;cin>>n>>q;
                string a;cin>>a;
                   
                vector<int> v(n+10, 0);
                v[0]=0;v[1]=1;
                if(a[1]==a[0]) v[1]=0;
                for(int i=2; i<n; i++){
                        if(a[i-2]==a[i]) v[i]=v[i-1];
                        else v[i]=i;
                }
                for(int i=0; i<q; i++){
                        int s, x;cin>>s>>x;x--;s--;
						string b = a;
						reverse(a.begin(), a.end());
                        if(a == b) x--;
                        if(v[x]<=s) cout<<0;
                        else cout<<ans[(x-s+1)];
                        cout<<'\n';
                }
        }
}
