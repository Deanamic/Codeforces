#include<bits/stdc++.h>
using namespace std;
vector<int> visited;
vector<vector<int> > adj;

void dfs(int x){
    visited[x] = 1;
    for(int i = 0; i < adj[x].size(); ++i){
        if(visited[adj[x][i]] == -1) {
            dfs(adj[x][i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<long long> v(n,0);
    vector<int> s(n,0);
    long long ans = 0;
    visited.resize(n,-1);
    adj.resize(n);
    long long self = 0;
    for(int i = 0 ; i < m; ++i){
        int x,y;
        cin >> x >> y;
        if(x == y) {
            ++self;
            s[--x] = 1;
        }
        else{
            ++v[--x];
            ++v[--y];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
    }
    for(int i = 0 ; i < n; ++i){
        if(v[i] or s[i]) {
            dfs(i);
            break;
        }
    }
    if(self > 1) ans += (self * (self-1))/2;
    ans += self*(m - self);
    for(int i = 0 ; i < n; ++i){
        if(v[i] > 1) ans += (v[i] * (v[i]-1))/2;
        if(visited[i] == -1 and (s[i] + v[i]) > 0) return cout << 0 << endl, 0;
    }
    cout << ans << endl;
}
