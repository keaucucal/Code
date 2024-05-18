const int mod = 1e9 + 7;
using ll = long long;

ll power(ll x, ll y) {
	ll ret = 1;
	while (y) {
		if (y & 1) ret = ret * x % mod;
		y >>= 1;
		x = x * x % mod;;
	}
	return ret;
}
