#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj;
int ans = 1;
vector<int> col;
queue<int> q;

void dfs(int x){
	set<int> s;
	for(int i = 0; i < adj[x].size(); ++i) s.insert(col[adj[x][i]]);
	int c = 1;
	while (col[x] == 0) {
		if(s.count(c) == 0) col[x] = c;
		ans = max(ans,col[x]);
		++c;
	}
	while(q.size()) {
		int nxt = q.front();
		q.pop();
		dfs(nxt);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	adj.resize(n);
	col.resize(n,0);
	while(m--){
		int x,y;
		cin >> x >> y;
		--x; --y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i = 1; i < n; ++i){
		q.push(i);
	}
	dfs(0);
	cout << ans << endl;
	for(int i : col) cout << i << ' ';
	cout << endl;
}
