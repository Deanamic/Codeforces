#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,A,cf,cm,Q;
	cin >> n >> A >> cf >> cm >> Q;
	pair<long long,int> v[n+1];
	for(int i = 0; i < n; ++i){
		cin >> v[i].first;
		v[i].second = i;
	}
	v[n].first = A;
	sort(v, v+n);
	long long pref[n+1];
	pref[0] = 0;
	for(int i = 1; i < n+1; ++i) pref[i] = pref[i-1] + v[i-1].first;

	long long itmax = -1, itmin = -1;
	long long curmax = n, curmin = n-1;
	long long ansmax = -1;
	int minval;
	while(Q >= 0 and curmax >= 0) {
		Q -= A - v[curmax].first;
		curmin = min(curmin, curmax - 1);
		if(Q >= 0) {
			long long curans = (n-curmax) * cf;
			while(curmin >= 0) {
				if((pref[curmin+1] + Q) / (curmin+1) >= v[curmin].first) break;
				--curmin;
			}
			if(curmin >= 0) curans += min(A, v[curmin].first + (Q - (v[curmin].first * (curmin+1) - pref[curmin+1]))/(curmin+1)) * cm;
			else curans += A * cm;
			if(curans > ansmax) {
				itmax = curmax;
				itmin = curmin;
				ansmax = curans;
				if(curmin >= 0)
				  minval = min(A, v[curmin].first + (Q - (v[curmin].first * (curmin+1) - pref[curmin+1]))/(curmin+1));
			}
		}
		--curmax;
	}
	cout << ansmax << endl;
	int ans[n];
	for(int i = 0; i < n; ++i) ans[v[i].second] = (i >= itmax ? A : (i <= itmin ? minval : v[i].first));
	for(int i = 0; i < n; ++i) {
		cout << ans[i] << ' ';
	}
	cout << endl;
}
