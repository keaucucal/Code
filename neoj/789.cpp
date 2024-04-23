#include <iostream>
using namespace std;

const int N = 100005;
int arr[N], temp[N];

void DC(int l, int r) { // [l, r]
	if (r - l <= 1) return;

	for (int i = l; i <= r; i++) temp[i] = arr[i];
	int cur = l;
	for (int i = l; i <= r; i += 2) arr[cur++] = temp[i];
	for (int i = l + 1; i <= r; i += 2) arr[cur++] = temp[i];


	int mid = (l + r) / 2;
	DC(l, mid);
	DC(mid + 1, r);
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) arr[i] = i;

	DC(1, n);
	for (int i = 1; i <= n; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
}
