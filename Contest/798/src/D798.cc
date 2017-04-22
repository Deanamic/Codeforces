#include<bits/stdc++.h>
using namespace std;

struct num{
	int a,b;
	int i;
	bool operator < (const num& n) const{
		return a > n.a;
	}
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> ans(n/2 + 1,-1);
	vector<num> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i].a;
	}
	for(int i = 0; i < n; ++i){
		cin >> v[i].b;
		v[i].i = i+1;
	}
	sort(v.begin(), v.end());
	ans[0] = v[0].i;
	for(int i = 1; i < n; i += 2){
		if(v[i+1].b > v[i].b) ans[i/2 + 1] = v[i+1].i;
		else  ans[i/2 + 1] = v[i].i;
	}
	if(n%2 == 0) ans[n/2] = v[n-1].i;
	cout << ans.size() << endl;
	for(int i : ans) cout << i << ' ';
	cout << endl;



}
