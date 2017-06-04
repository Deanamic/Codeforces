#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,f;
	cin >> n >> f;
	vector<long long> rev;
	long long ans = 0;
	for(int i = 0; i < n; ++i){
		long long k,l;
		cin >> k >> l;
		if(k > l) rev.push_back(0);
		else if(2*k < l) rev.push_back(k);
		else rev.push_back(l-k);
		ans += min(k, l);
	}
	sort(rev.rbegin(), rev.rend());
	for(int i = 0; i < f; ++i){
		ans += rev[i];
	}
	cout << ans << endl;

}
