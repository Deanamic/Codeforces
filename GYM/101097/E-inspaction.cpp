#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef vector <int> vi;
typedef vector <vi> vvi;

vvi g;
vi v;
vi sol;
int n;

void dfs1(int x, int y) {
    v[x] = 1;
    for (int j = 0; j < g[x].size(); ++j) {
        if(g[x][j] != y) {
            dfs1(g[x][j], x);
            v[x] += v[g[x][j]];
        }
    }
}

int dfs3(int x, int p, int y, int &a){
    int sum = 0;
    a = max(a , p-1);
    for (int i = 0; i < g[x].size(); ++i){
        if(g[x][i] != y){
            sum += p;
            //cout << g[x][i] <<' ' << p << endl;
            sum += dfs3(g[x][i] , p+1, x , a);
        }
    }
    return sum;
}

void dfs2(int x, int y) {
    bool bo = 0;
    if (x != y and v[x] > n-v[x]-1) sol[y] = -1;
    if (x != y and n - v[x] - 1 > n/2) sol[x] = -1; 
    for(int i = 0; i < g[x].size(); ++i) {
        if (g[x][i] != y) {
            dfs2(g[x][i], x);
            bo = 1;
        }
    }
    if (not bo) sol[x] = -1;
    if (sol[x] == 0) {
        int Sum = 0;
        int r = -1;
        int mx = 0;
        for (int i = 0; i < g[x].size(); ++i){
            int m = 0;
            Sum++;
            Sum += dfs3(g[x][i] , 2, x , m);
            if(v[g[x][i]] == n - v[g[x][i]]) {
                int r = m;
            }
            mx = max(mx, m);
        }
        
        if(r == -1){
           
            sol[x] = 2*Sum - mx;
        }
        else {
            sol[x] = 2*Sum - r;
        }
 
    }
}





int main() {
    //~ freopen("inspection.in", "r", stdin);
    //~ freopen("inspection.out", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    g = vvi(n);
    sol = v = vi(n,0);
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    
    dfs1(0, 0);

    dfs2(0, 0);
    //for(int i = 0; i < n; ++i) cout << v[i] << endl;
    for(int i = 0; i < n; ++i) cout << sol[i] << '\n';
    
}
