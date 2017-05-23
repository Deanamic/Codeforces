#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, t, k ,d;
	cin >> n >> t >>k >> d;
	if(k*((d+t)/t) < n) cout << "YES" << endl;
	else cout << "NO" << endl;
}
