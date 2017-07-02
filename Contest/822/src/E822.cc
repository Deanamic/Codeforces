#include<bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 7;
const int MAXN = 5000001;
long long din[MAXN];
long long gar[MAXN];

inline long long calc(long long i){
	return ((i*(i-1))/(2LL))%MOD;
}

long long comp(int x) {
	if(din[x] != -1) return din[x];
	long long i = gar[x];
	if(i != x) return din[x] = (comp(x/i) + (x/i)*calc(i))%MOD;
	return din[x] = calc(x);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(din, -1, sizeof din);
	memset(gar, -1, sizeof gar);
	din[0] = din[1] = 0; din[2] = 1;
	gar[0] = gar[1] = 1;
    for (long long i = 2; i < MAXN; i++){
        if (gar[i] == -1){
			gar[i] = i;
            for (long long j = 2; j*i < MAXN; j++) if(gar[i*j] == -1) gar[i*j] = i;
        }
    }
	long long t,l,r;
	cin >> t >> l >>r;
	long long e = 1;
	long long ans = 0;
	for(int i = l; i < r + 1; ++i) {
		ans += (e*comp(i))%MOD;
		ans = ((ans%MOD)+MOD)%MOD;
		e *= t;
		e = ((e%MOD)+MOD)%MOD;
	}
	cout << ((ans%MOD)+MOD)%MOD << endl;

}
