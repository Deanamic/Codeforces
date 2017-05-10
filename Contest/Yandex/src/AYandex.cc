#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int ans = 1;
	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		v[--x] = i;
	}
	for(int i = 1; i < n; ++i){
		if(v[i] < v[i-1]) ++ans;
	}
	cout << ans << endl;



}
