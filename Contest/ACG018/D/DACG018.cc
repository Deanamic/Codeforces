#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
vector<pair<int,int>> adj[MAXN];
int sz[MAXN] = {0};
long long d[MAXN];
int n;
int cen = -1;
long long ans = 0;

int dfs(int x, int p) {
	sz[x] = 1;
	for(auto u : adj[x]) {
		if(u.first != p) {
			sz[x] += dfs(u.first, x);
			if(sz[x] >= (n+1)/2 and cen == -1) cen = x;
		}
	}
	return sz[x];
}

int ddfs(int x, int p, long long dth) {
	d[x] = dth;
	ans += 2*d[x];
	sz[x] = 1;
	for(auto u : adj[x]) {
		if(u.first != p) {
			sz[x] += ddfs(u.first, x, dth + u.second);
		}
	}
	return sz[x];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n-1; ++i){
		int a,b,c;
		cin >> a >> b >> c;
		--a; --b;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	dfs(0, 0);
	ddfs(cen, cen, 0);

	if(n&1) {
		long long mn = 1e9;
		for(auto u : adj[cen]) {
			mn = min(mn, d[u.first]);
		}
		cout <<  ans - mn << endl;
	}
	else {
		for(auto u : adj[cen]) {
			if(sz[u.first] == (n/2))
				return cout <<  ans - d[u.first] << endl, 0;
		}

		long long mn = 1e9;
		for(auto u : adj[cen]) {
			mn = min(mn, d[u.first]);
		}
		cout << ans - mn << endl;
	}
}
