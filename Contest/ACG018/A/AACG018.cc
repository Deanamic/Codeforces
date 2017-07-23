#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	int v[n];
	int big = 0, done = 0;
	cin >> v[0];
	int gcd = v[0];
	for(int i = 1; i < n; ++i){
		cin >> v[i];
		gcd = __gcd(v[i], gcd);
	}
	sort(v, v+n);
	for(int i = n-1; i >= 0 and v[i] >= k; ++i) {
		if((v[i] - k) % gcd == 0) return cout << "POSSIBLE" << endl, 0;
	}
	cout << "IMPOSSIBLE" << endl;
}
