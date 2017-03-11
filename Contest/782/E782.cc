#include<bits/stdc++.h>
using namespace std;

vector<vector<int> >  Eulerian_tour;
vector<vector<int> > adj;
vector<int> vis;



    int n,m,k;
int row = 0;

void Eulerian_dfs(int p, int node){
    if(Eulerian_tour[row].size() == (2*n+k-1)/k) ++ row;
    Eulerian_tour[row].push_back(node);
    for (int i = 0; i < adj[node].size(); ++i) {
        if (!vis[adj[node][i]]) {
            vis[adj[node][i]] = 1;
            Eulerian_dfs(node, adj[node][i]);
            if(Eulerian_tour[row].size() == (2*n+k-1)/k) ++ row;
            Eulerian_tour[row].push_back(node);
        }
    }
}

int main(){
    cin >> n >> m >> k;
    vis = vector<int>(n,0);
    adj.resize(n);
    Eulerian_tour.resize(k);
    for(int i = 0; i < m; ++i){
        int x,y;
        cin >> x >> y;
        if(x != y){
            --x; --y;
            adj[x].push_back(y) ;
            adj[y].push_back(x) ;
        }
    }
    vis[0] = 1;
    Eulerian_dfs(0, 0);
    for(int i = 0; i < k; ++i){
        if(Eulerian_tour[i].size()){
            cout << Eulerian_tour[i].size() << ' ';
            for(int j = 0; j < Eulerian_tour[i].size(); ++j){
                cout << Eulerian_tour[i][j]+1 << ' ';
            }
        }

        else cout << "1 1" << endl;

    }
}
