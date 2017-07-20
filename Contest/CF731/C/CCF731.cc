#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
int vis[MAXN];
int col[MAXN];
int cnt[MAXN];
vector<int> adj[MAXN];
int mx;
int sz;
queue<int> q;
int dfs(int x) {
	++sz;
	vis[x] = 1;
	if(!cnt[col[x]]) q.push(col[x]);
	mx = max(mx, ++cnt[col[x]]);
	for(int y : adj[x]) if(!vis[y]) dfs(y);
}

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i){
        cin >> col[i];
    }
    for(int i = 0; i < m; ++i){
        int x,y;
        cin >> x  >> y;
        --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int ans = 0;
	memset(vis, 0, sizeof vis);
    for(int i = 0; i < n; ++i){
        if(!vis[i]){
			while(q.size()) {
				cnt[q.front()] = 0;
				q.pop();
			}
            mx = 0;
			sz = 0;
            dfs(i);
            ans += sz - mx;
        }
    }
    cout << ans << endl;
}
