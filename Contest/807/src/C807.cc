#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		long long x,y,p,q;
		cin >> x >> y >> p >> q;
		if(p == q) {
			cout << (x == y ? 0 : -1) << endl;
			continue;
		}
		if ( p == 0){
			cout << (x == 0 ? 0 : -1) << endl;
			continue;
		}
		long long l = 0, r = 1e9;
		long long ans = 1e18;
		while(l + 1 < r){
			long long m = (l+r)/2;
			long long lambda = m*p-x;
			long long c = y + lambda;
			long long mu = (q*m)-c;
			if(mu >= 0 and lambda >= 0){
				r = m;
			}
			else l = m;
		}
		//cerr << r << endl;
		for(int i = 0; i < 1000; ++i){
			long long m = i+r;
			long long lambda = m*p-x;
			long long c = y + lambda;
			long long mu = (q*m)-c;
			ans = min(ans, lambda + mu);
		}
		cout << ans << endl;
	}
}
