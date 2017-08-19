#include<bits/stdc++.h>
using namespace std;

struct Edge {
	int u, v, id, used;
	int get(int x) {
		return u ^ v ^ x;
	}
} E[500010];

vector<int> adj[300010];
int aux[300010];
int deg[300010];
int nxt[300010];
int d[300010];
int vis[300010];
vector<int> ans;
int l = 0;

int getans(int u) {
	vis[u] = 1;
	int e = 0;
	for(int i : adj[u]){
		int v = E[i].get(u);
		if(vis[v] == 0) {
			if(getans(v) == 1) {
				ans.push_back(i);
				++e;
			}
		}
	}
	if(d[u] == -1) return 0;
	if((d[u]&1) == (e&1)) return 0;
	return 1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(vis, 0, sizeof vis);
	int n, m;
	cin >> n >> m;
	int aux = 0;
	int odd = 0;
	for(int i = 0; i < n; ++i){
		cin >> d[i];
		if(d[i] == -1) aux = i;
		if(d[i] == 1) ++odd;
	}
	if(odd&1 and d[aux] != -1) return cout << -1 << endl, 0;

	for(int i = 0; i < m; ++i){
		int x,y;
		cin >> x >> y;
		--x, --y;
		E[l] = {x,y,l,0};
		adj[x].push_back(l);
		adj[y].push_back(l);
		l++;
	}

	if(getans(aux)) return cout << -1 << endl, 0;
	cout << ans.size() << endl;
	for(int i : ans) {
		if(i < m) cout << i + 1 << ' ';
	}
	cout << endl;

}
