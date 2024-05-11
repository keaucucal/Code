#include <iostream>
#include <vector>
#include <random>
#include <string>
using namespace std;
using ll = long long;

struct RandomizedHash {
	vector<ll> hash, power; // 哈希值前綴和 / 紀錄Base冪次 
	ll MOD, BASE; // B / A

	RandomizedHash(const string &s) {
		mt19937 rng(807); // 設定random number generator的種子為807
		uniform_int_distribution<> dist(257, 1e9 + 7); // 設定範圍為 257 ~ 1000000007
		MOD = dist(rng); // 隨機設定B
		BASE = dist(rng); // 隨機設定A

		int n = s.size();
		hash.resize(n + 1, 0);
		power.resize(n + 1, 1);

		for (int i = 0; i < n; i++) {
			hash[i + 1] = (hash[i] * BASE + s[i]) % MOD;
			power[i + 1] = (power[i] * BASE) % MOD;
		}
	}

	ll getHash(int l, int r) {
		// 取得l ~ r 子字串的哈希值
		return (hash[r + 1] - hash[l] * power[r - l + 1] % MOD + MOD) % MOD;
	}
};

int main() {
	string input;
	cout << "Enter a string: ";
	getline(cin, input);
	RandomizedHash hasher(input);

	cout << "Hash of the entire string: " << hasher.getHash(0, input.length() - 1) << endl;
}
