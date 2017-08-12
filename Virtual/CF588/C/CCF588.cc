#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int v[2000000] = {};
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		v[x]++;
	}
	int ans = 0;
	for(int i = 0; i < 1500000; ++i){
		int t = v[i]/2;
		v[i+1] += t;
		ans += v[i] & 1;
	}
	cout << ans << endl;
}
