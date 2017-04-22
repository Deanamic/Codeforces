#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int ans = 0;
	int odd = 0;
	int gcd = 0;
	while(n--){
		int x;
		cin >> x;
		gcd = __gcd(gcd, x);
		if(x%2) ++odd;
		else{
			ans += (odd)/2;
			if(odd%2) ans += 2;
			odd = 0;
		}
	}
	ans += (odd)/2;
	if(odd%2) ans += 2;
	cout << "YES" << endl;
	if(gcd == 1) cout << ans << endl;
	else cout << 0 << endl;

}
