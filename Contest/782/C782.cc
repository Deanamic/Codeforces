#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> c;
vector<vector<int> > adj;
int mx = 0;

void dfs(int p, int pcol, int col, int nod){
    c[nod] = col;
    mx = max(c[nod],mx);
    int paint = 1;
    for(int i = 0; i < adj[nod].size(); ++i){
        if(p != adj[nod][i]){
            if(paint == col) ++paint;
            if(paint == pcol) ++paint;
            if(paint == col) ++paint;
            //cout << adj[nod][i]+1 << " color: " << paint << endl;
            dfs(nod,c[nod], paint, adj[nod][i]);
            ++paint;
        }
    }
}

int main(){

    cin >> n;
    c = vector<int> (n,0);
    adj.resize(n);
    for(int i = 0; i < n-1; ++i){
        int x,y;
        cin >> x >> y;
        --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    c[0] = 1;
    dfs(0,0,1,0);
    cout << mx << endl;
    for(int i = 0; i < n; ++i){
        cout << c[i] << ' ';
    }
    cout << endl;

}
