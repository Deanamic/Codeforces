#include<bits/stdc++.h>
using namespace std;

int range[100010];
int Seg[400000];
long long dp[100010];

int cmp(int i, int j) {
	if(i == -1) return j;
	if(j == -1) return i;
	return (range[i] > range[j] ? i : j);
}
void build(int id, int l, int r) {
	if(l + 1 >= r) {
		Seg[id] = l;
		return;
	}
	int mid = (l + r) >> 1;
	build(id << 1, l, mid);
	build(1 |(id << 1), mid , r);
	Seg[id] = cmp(Seg[id << 1], Seg[1 | (id << 1)]);
}

int query(int id, int l, int r, int x, int y) {
	if(l >= y || r <= x) return -1;
	if(l >= x && r <= y) return Seg[id];
	int mid = (l + r) >> 1;
	int q1 = query(id << 1, l, mid, x, y);
	int q2 = query(1 |(id << 1), mid , r, x, y);

	return cmp(q1, q2);
}

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n-1; ++i) {
		cin >> range[i];
	}
	range[n-1] = n;
	dp[n-1] = 0;
	build(1, 0, n);
	long long ans = 0;
	for(int i = n-2; i >= 0; --i) {
		int p = query(1, 0, n, i + 1, range[i]);
		ans += dp[i] = (range[i] - i - 1) + dp[p] - (range[i] - p - 1) + (n - range[i]);
	}
	cout << ans << endl;
}
