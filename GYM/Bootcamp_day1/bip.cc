#include <bits/stdc++.h>
using namespace std;


typedef vector < int > VE;
typedef vector < VE > VVE;
typedef long long LL;

int n, m;
VVE adj;
VE mat2;
VE mat1;
VE vis1;
VE vis2,pare,visit;

void dfs(int pos){
    for (int i = 0; i < adj[pos].size(); i++) {
        if (mat1[pos] != adj[pos][i]) {
            if (!vis2[adj[pos][i]]) {
                vis2[adj[pos][i]] = 1;
                if (mat2[adj[pos][i]] == -1) {
                }
                else if (!vis1[mat2[adj[pos][i]]]) {
                    vis1[mat2[adj[pos][i]]] = 1;
                    dfs(mat2[adj[pos][i]]);
                }
            }
        }
    }
}

bool kuhn(int a){
    if (visit[a]) return false;
    visit[a] = 1;
    for (int i = 0; i < adj[a].size(); ++i) {
        if (pare[adj[a][i]] == -1 or kuhn(pare[adj[a][i]])) {
            pare[adj[a][i]] = a;
            return true;
        }
    }
    return false;
}

void match(){
    for (int i = 0; i < n; ++i) {
        visit = vector<int> (n, 0);
        kuhn(i);
    }
}


int main(){
    int n, m;

    cin >> n >> m;
    adj = VVE(n);
    mat1 = VE(n, -1);
    pare = mat2 = VE(m, -1);
    vis1 = VE(n, 0);
    vis2 = VE(m, 0);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x;
        for (int j = 0; j < x; j++) {
            cin >> y;
            y--;
            adj[i].push_back(y);
        }
    }
    match();
    for (int i = 0; i < m; i++) {
        int x = pare[i];
        if (x != -1) {
            mat1[x] = i;
            mat2[i] = x;
        }
    }
    for (int i = 0; i < n; i++) {
        if (mat1[i] == -1 and !vis1[i]) {
            vis1[i] = 1;
            dfs(i);
        }
    }
    int cont1 = 0;
    for (int i = 0; i < n; i++) {
        if (!vis1[i]) cont1++;
    }
    cout << cont1 << endl;
    for (int i = 0; i < n; i++) {
        if (!vis1[i]) cout << (i ? " " : "") << i + 1;
    }
    cout << endl;

} // main
