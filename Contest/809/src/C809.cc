#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<long long> v(n),s(n,0);
	vector<long long> pow(n);
	pow[0] = 1;
	for(int i = 1; i < n; ++i){
		pow[i] = (pow[i-1] << 1);
		pow[i] %= MOD;
	}

	for(int i = 0; i < n; ++i){
		cin >> v[i];

	}
	sort(v.begin(), v.end());
	s[n-1] = v[n-1];
	for(int i = n - 2; i >= 0; --i){
		s[i] += 2*s[i+1];
		s[i] += v[i];
		s[i] %= MOD;
	}
	long long ans = 0;
	for(int i = 0; i < n-1; ++i){
		ans += ((s[i+1] - (pow[n-i-1]-1)*v[i])%MOD + MOD)%MOD;
		ans %= MOD;
	}
	cout << ans << endl;

}
