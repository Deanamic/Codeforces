#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200010;

int a[MAXN];
long long d[MAXN];
int p[20][MAXN];
vector<pair<int,int>> adj[MAXN];
int pref[MAXN] = {};

void depth(int x, long long dth) {
	d[x] = dth;
	for(pair<int,int> y : adj[x]) depth(y.first, y.second + dth);
}

void findnode(int x, long long dth) {
	int it = 0;
	while(it < 20 and p[it][x] != -1 and d[p[it][x]] >= dth) ++it;
	if(it == 0) {
		if(p[0][x] >= 0) pref[p[0][x]]--;
		return;
	}
	return findnode(p[it-1][x], dth);
}

int getans(int x) {
	for(pair<int,int> y : adj[x]) pref[x] += getans(y.first);
	return pref[x];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 1; i < n; ++i){
		int x,y;
		cin >> x >> y;
		--x;
		adj[x].push_back({i, y});
		p[0][i] = x;
	}
	depth(0, 0);
	for(int i = 0; i < 20; ++i){
		p[i][0] = -1;
	}
	for(int i = 1; i < 20; ++i) {
		for(int j = 1; j < n; ++j){
			if(p[i-1][j] >= 0) p[i][j] = p[i-1][p[i-1][j]];
			else p[i][j] = -1;
		}
	}

	for(int i = 0; i < n; ++i) {
		if(p[0][i] != -1) pref[p[0][i]]++;

		findnode(i, d[i] - a[i]);

	}

	getans(0);

	for(int i = 0; i < n; ++i) cout << pref[i] << '\n';
}
