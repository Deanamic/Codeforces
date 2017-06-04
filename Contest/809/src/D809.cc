#include<bits/stdc++.h>
using namespace std;

string s;

bool query(int x){
	cout << 1 << ' ' << x << ' ' << x+1 << endl;
	cin >> s;
	return (s == "NIE");
}

int binary(int l, int r){
	while(l < r){
		int mid = (l+r)/2;
		if(query(mid)) l = mid+1;
		else r = mid;
	}
	return r;
}

int main(){
	int n, k;
	cin >> n >> k;
	int ans1, ans2;
	ans1 = binary(1,n);
	if(ans1 != n){
		ans2 = binary(ans1+1,n);
		cout << 1 << ' ' << ans2 << ' ' << ans1 << endl;
		cin >> s;
		if(s == "TAK") return cout << 2 << ' ' << ans1 << ' ' << ans2 << endl, 0;
	}
	cout << 2 << ' ' << ans1 << ' ' << binary(1,ans1-1) << endl;
}
