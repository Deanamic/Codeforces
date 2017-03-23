#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> vis;

bool check(int i){
    int ref = adj[i].size();
    for(int j = 0; j < adj[i].size(); ++j){
        if(adj[adj[i][j]].size() != ref) return true;
        vis[adj[i][j]] = 1;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    for(int i = 0; i < m; ++i){
        int x,y;
        cin >> x >> y;
        --x;
        --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vis = vector<int> (n,-1);
    for(int i = 0; i < n; ++i){
        if(vis[i] == -1){
            vis[i] = 1;
            if(check(i)){
                return cout << "NO" << endl, 0;
            }
        }
    }
    return cout << "YES" << endl, 0;

}
