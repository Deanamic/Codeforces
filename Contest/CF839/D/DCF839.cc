#include<bits/stdc++.h>
using namespace std;

const long long oo = 1e6 + 10;
const long long MOD = 1e9 + 7;
long long f[oo];
long long trueset[oo];
int p[1000010];

long long get(long long n) {
	return (n * p[n-1])%MOD;
}

inline void fix(long long& x) {
	x = (x%MOD + MOD)%MOD;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(f, 0, sizeof f);
	memset(trueset, 0, sizeof trueset);
		p[0] = 1;
	for(int i = 1; i < oo; ++i) {
	  p[i] = 2*p[i-1];
	  p[i] %= MOD;
	}
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		f[x]++;
	}
	long long ans = 0;

	for(long long i = 1000000; i >= 2; --i){
		long long good = f[i];
		long long t = 0;
		for(long long j = 2; i*j <= 1000000; ++j){
			good += f[i*j];
			t += trueset[i*j];
			fix(t);
		}
		if(good)
			trueset[i] = get(good) - t;
		fix(trueset[i]);
		ans += i*trueset[i];
		fix(ans);

	}
	fix(ans);
	cout << ans << endl;
}
