#include <bits/stdc++.h>
using namespace std;

vector<queue<int> > vv;
vector<int> vis,v;
map<pair<int,int>,int> color;
int dfs(int i,int& t, int& mx){
    if(vv[i].size() == 0) return 0;
    vis[i] = 0;
    ++color[{v[i],t}];
    mx = max(color[{v[i],t}],mx);
    int add = 1;
    while(not vv[i].empty()){
        int x = vv[i].front();
        vv[i].pop();
        if(vis[x] == -1) {
            add += dfs(x ,t , mx);
        }
    }
    return add;
}

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    v = vector<int> (n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    vv = vector<queue<int> >(n);
    vis = vector<int>(n,-1);
    for(int i = 0; i < m; ++i){
        int x,y;
        cin >> x  >> y;
        --x; --y;
        vv[x].push(y);
        vv[y].push(x);
    }
    int ans = 0;
    int t = 0;
    for(int i = 0; i < n; ++i){
        if(vis[i] == -1){
            int mx = 0;
            ans += dfs(i,t,mx);
            ans -= mx;
            ++t;
        }
    }
    cout << ans << endl;


}
