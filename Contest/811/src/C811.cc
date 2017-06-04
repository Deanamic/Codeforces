#include<bits/stdc++.h>
using namespace std;

vector<vector<int> >  app(5001);
vector<int> l(5001,-1), f(5001,-1);
vector<int> v;

int getans(int i, int j){
	if(i >= j) return 0;
	if(f[v[i]] < i) return 0;
	vector<int> see(5001,0);
	int x = 0;
	int furt = l[v[i]];
	for(int I = i; I <= furt; ++I){
		see[v[I]] = 1;
		if(i > f[v[I]]) return 0;
		furt = max(furt, l[v[I]]);
	}
	if(furt >= j) return 0;
	for(int I = 0; I < 5001; ++I){
		if(see[I]) x ^= I;

	}
	int ans = 0;
	for(int I = 0; I < app[v[i]].size() ; ++I){
		ans += getans( app[v[i]][I] + 1, app[v[i]][I+1]);
	}
	return max(x + getans(furt + 1, j), ans);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	v.resize(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
		if(f[v[i]] == -1) f[v[i]] = i;
		l[v[i]] = i;
		app[v[i]].push_back(i);
	}
	for(int i = 0; i < n; ++i){
		app[i].push_back(n);
	}
	cout << getans(0,n) << endl;
}
