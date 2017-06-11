#include<bits/stdc++.h>
using namespace std;

vector<int> la(5010), fi(5010);
vector<int> v;
vector<int> dp;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	v.resize(n);
	dp.resize(n,0);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	for(int i = 0; i < n; ++i){
		la[v[i]] = i;
	}
	for(int i = n-1; i >= 0; --i){
		fi[v[i]] = i;
	}

	for(int i = 0; i < n; ++i) {
		if(i) dp[i] = max(dp[i-1], dp[i]);
		bool can = 1;
		int l = fi[v[i]];
		int r = la[v[i]];
		int ans = 0;
		if(i == r) {
			vector<int> app(5010,0);
			for(int j = r; can and j >= l; --j){
				if(!app[v[j]]) ans ^= v[j];
				app[v[j]] = 1;
				if(la[v[j]] > r) can = 0;
				l = min(l, fi[v[j]]);
			}
			if(can) dp[i] = max(dp[i], (l > 0 ? dp[l-1] : 0) + ans);
		}

	}
	cout << dp[n-1] << endl;
}
