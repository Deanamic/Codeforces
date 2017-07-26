#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
long long inv[1010];
long long fact[1010];

int over(long long n, long long k) {
	long long ans = fact[n] * inv[n-k];
	ans %= MOD;
	ans *= inv[k];
	return ans%MOD;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, k;
	cin >> n >> k;
	inv[1] = 1;
	for (int i=2; i<1010; ++i)
		inv[i] = (MOD - (MOD/i) * inv[MOD%i] % MOD) % MOD;

	fact[1] = 1;
	for (int i=2; i<1010; ++i) fact[i] = (fact[i-1] * i) % MOD;

	long long ans = over(n, k);
	for(int i = k+2; i <= n; ++i){
		ans <<= 1;
		ans %= MOD;
	}
	cout << ans << endl;
}
