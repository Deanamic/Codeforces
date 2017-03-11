#include <bits/stdc++.h>
using namespace std;


int n;
int cen = -1;
vector<vector<int> > adj;
vector<int> sz;
bool d = 1;
int ans;

int dfs(int now, int p){
    sz[now] = 1;
	for(auto x: adj[now]){
		if(x != p){
			dfs(x, now);
			sz[now] += sz[x];
			if(sz[now] >= n/2 and cen == -1)
				cen = now;
		}
	}
	return sz[now];
}

set<int> dfs1(int now, int p){
    set<int> s,s1;
    //cout << now << endl;
    for(int i = 0; d and i < adj[now].size(); ++i){
        int x = adj[now][i];
		if(x != p){
			s1 = dfs1(x, now);
            if(now != cen and s1.size() > 1){
                d = 0;
            }
			for(auto it: s1){
                s.insert(it+1);
            }
		}
	}
    if(now == cen){
        if(s.size() == 1) ans = *s.begin();
        else if(s.size() == 2) ans = *s.begin() + *(++s.begin());
        else {
            d = 0;
        }
    }
    if(s.size() == 0) s.insert(0);
    return s;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n;
    adj.resize(n);
    sz.resize(n,0);
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;--u;--v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0, 0);
    dfs1(cen,cen);
    if(d){
        while(ans%2 == 0)ans/=2;
        cout << ans << endl;
    }
    else cout << -1 << endl;
}
