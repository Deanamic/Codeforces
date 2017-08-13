#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100010];

long double dfs(int u, int p) {
	long double l = 0;
	for(int v : adj[u]) {
		if(v != p){
			l += (1 + dfs(v, u))/(long double)(adj[u].size() - (u != p));
		}
	}
	return l;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.setf(ios::fixed);
	cout.precision(14);
	int n;
	cin >> n;
	for(int i = 0; i < n-1; ++i){
		int x,y;
		cin >> x >> y;
		--x; --y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cout << dfs(0,0) << endl;
}
