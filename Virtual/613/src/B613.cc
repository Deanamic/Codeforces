#include<bits/stdc++.h>
using namespace std;

long long n, A, cf, cm, C;
pair<int,int> v[100010];

int ans[100010];

int getmx(int l) {
	int mx = l * cm;
	for(int i = 0; i < n and v[i].first < l; ++i) {
		int t = l - v[i].first;
		ans[v[i].second] += t;
		C -= t;

	}
	for(int i = n-1; C > 0 and i >= 0; --i){
		int t = A - v[i].first;
		if(t <= C){
			C -= t;
			ans[v[i].second] += t;
			mx += cf;
		}
		else C = 0;
	}
	return mx;

}
bool can(int m) {
	long long k = C;
	for(int i = 0; i < n and v[i].first < m; ++i) {
		int t = m - v[i].first;
		k -= t;
	}
	if(k < 0) return false;
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> A >> cf >> cm >> C;
	for(int i = 0; i < n; ++i) {
		cin >> ans[i];
		v[i] = {ans[i], i};
	}
	sort(v, v + n);

	int l = 0, r = n + 1;
	while(l + 1 < r) {
		long long m = (l + r) >> 1;
		if(can(m)) l = m;
		else r = m;
	}
	cout << getmx(l) << endl;
	for(int i = 0; i < n; ++i) cout << ans[i] << ' ';
}
