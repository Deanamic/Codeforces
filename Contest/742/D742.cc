#include <bits/stdc++.h>
using namespace std;

vector<vector<long long> > adj;
vector<long long> vis;
vector<long long> b;
vector<long long> we;
vector<long long> group;

void f(long long id){
    if(vis[id] == -1){
        group.push_back(id);
        vis[id] = 1;
        for(long long i = 0; i < adj[id].size(); ++i){
            if(vis[adj[id][i]] == -1){
                f(adj[id][i]);
            }
        }
    }
    return;
}

int main(){
    long long n,m,w;
    cin >> n >> m >> w;
    vis = vector<long long>(n,-1);
    vector<vector<long long> > dp(2,vector<long long>(w+1,0));
    b = we = vector<long long>(n);
    adj = vector<vector<long long> >(n);
    for(long long i = 0; i < n; ++i){
        cin >> we[i];
    }
    for(long long i = 0; i < n; ++i){
        cin >> b[i];
    }
    for(long long i = 0; i < m; ++i){
        long long x,y;
        cin >> x >> y; --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    long long beauty = 0;
    for(long long i = 0; i < n; ++i){
        if(vis[i] == -1){
            group.clear();
            f(i);
            long long bg = 0, wg = 0;
            for(long long j = 0; j < group.size(); ++j){
                bg += b[group[j]];
                wg += we[group[j]];
            }
            for(long long j = 0; j < w+1; ++j) dp[(i+1)%2][j] = 0;
            for(long long j = 0; j < w+1; ++j){
                if(dp[i%2][j] != 0 or j == 0){
                    for(long long k = 0; k < group.size(); ++k){
                        if(j + we[group[k]] <= w){
                            dp[(i+1)%2][j + we[group[k]]] = max(dp[i%2][j] + b[group[k]] , dp[(i+1)%2][j + we[group[k]]]);
                            beauty = max(beauty,dp[(i+1)%2][j + we[group[k]]]);
                        }
                    }
                    if(j + wg <= w){
                        dp[(i+1)%2][j + wg] = max(dp[i%2][j] + bg , dp[(i+1)%2][j + wg]);
                        beauty = max(beauty,dp[(i+1)%2][j + wg]);
                    }
                    dp[(i+1)%2][j] = max(dp[(i+1)%2][j],dp[i%2][j]);
                }
            }
        }
    }
    cout << beauty << endl;
}
