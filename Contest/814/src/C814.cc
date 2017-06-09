#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int q;
	cin >> q;
	int dp[26][n+1];
	memset(dp, -1, sizeof dp);
	while(q--) {
		int m;
		char c;
		cin >> m >> c;
		if(dp[c-'a'][m] != -1) cout << dp[c-'a'][m] << endl;
		else{
			int it1 = 0;
			int it2 = -1;
			int dif = 0;
			int ans = 0;
			while(it1 < n){
				if(s[it1] != c) ++dif;
				while(dif > m) {
					++it2;
					if(s[it2] != c) --dif;
				}
				ans = max(ans, it1 - it2);
				++it1;
			}
			dp[c-'a'][m] = min(n,ans);
			cout << dp[c-'a'][m] << endl;
		}
	}
}
