#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	int leaf[n];
	int sz[n];
	memset(sz, 0, sizeof sz);
	memset(leaf, 0, sizeof leaf);
	vector<int> adj[n];
	for(int i = 0; i < m; ++i){
		int x,y;
		cin >> x >> y;
		--x;
		--y;
		adj[y].push_back(x);
		leaf[x] = 1;
		sz[x]++;
	}
	int pos = n;
	int ans[n];
	priority_queue<int> pq;
	for(int i = 0; i < n; ++i) {
		if(leaf[i] == 0) pq.push(i);
	}

	while(pq.size()) {
		int x = pq.top();
		pq.pop();

		ans[x] = pos--;
		for(int y : adj[x]) {
			if(--sz[y] == 0) pq.push(y);
		}
	}

	for(int i = 0; i < n; ++i) cout << ans[i] << ' ';
	cout << endl;



}
