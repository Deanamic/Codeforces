#include<bits/stdc++.h>
using namespace std;

struct voucher {
	long long l, r, c;
	long long mn;
	bool operator < (voucher v) {
		return l < v.l;
	}
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	cin >> n >> x;
	vector<voucher > adj[x+1];

	for(int i = 0; i < n; ++i){
		int l,r,c;
		cin >> l >> r >> c;
		int d = r - l + 1;
		if(d > x) continue;
		adj[d].push_back({l,r,c});
	}
	for(int i = 0; i < x; ++i){
		sort(adj[i].begin(), adj[i].end());
		long long mn = 1e9;
		for(int j = 0; j < adj[i].size(); ++j){
			mn = adj[i][j].mn = min(adj[i][j].c, mn);
		}
	}
	long long ans = 1e11;
	for(int i = 0; i < x; ++i){
		for(int j = 0; j < adj[i].size(); ++j){
			int cost = adj[i][j].c;
			int st = adj[i][j].l;
			int l = -1, r = adj[x-i].size();
			while(l + 1 < r) {
				int m = (l + r)/2;
				if(adj[x-i][m].r < st) l = m;
				else r = m;
			}
			if(l == -1) continue;
			ans = min(ans, cost + adj[x-i][l].mn);
		}
	}
	cout << (ans > 1e10 ? -1 : ans) << endl;


}
