#include <bits/stdc++.h>
using namespace std;


struct SparseTable {
    vector<vector<int> > ST;
    vector<int > P;
    int N;
    int MAXLOG = 0;

    void build(int n, const vector<int>& V){
        N = n;
        while ((1 << MAXLOG) <= N) ++MAXLOG;
        ST = vector<vector<int> > (N, vector<int> (MAXLOG));
        P = vector<int> (N + 1);
        int LOG = 0;
        for (int i = 1; i < N + 1; ++i) {
            P[i] = ((1 << LOG) > i ? LOG - 1 : ++LOG - 1);
        }
        // Dynamic Sparse table building
        for (int i = 0; i < N; ++i) {
            ST[i][0] = i;
        }
        for (int j = 1; j < MAXLOG; ++j) {
            for (int i = 0; i + (1 << j) - 1 < N; ++i) {
                if (V[ST[i][j - 1]] < V[ST[i + (1 << (j - 1))][j - 1]])
                    ST[i][j] = ST[i][j - 1];
                else
                    ST[i][j] = ST[i + (1 << (j - 1))][j - 1];
            }
        }
    } // build

    int query(int l, int r, const vector<int>& V){
        int LOG = P[r - l + 1];

        // we need an interval range such the we can cover [l,r] with
        // [l , l + 2^LOG) and [r - 2^LOG + 1, r+1)
        // hence we need the maximum LOG, such that 2^LOG is smaller than
        // the range or [l,r]
        // Which has been preprocessed before
        if (V[ST[l][LOG]] < V[ST[r - (1 << LOG) + 1][LOG]])
            return ST[l][LOG];
        return ST[r - (1 << LOG) + 1][LOG];

    }
};

struct Tree {
    vector<vector<int> > adj;
    int V, E;
    int LOG;
    int root;
    int t = 0;
    vector<vector<int> > Eulerian_tour;
    vector<int> time_in, time_out;
    vector<int> Depth;
    SparseTable S;
    // This vectors will save the ith value in the eulerian tour and its depth
    // And the first appereance of each node
    // Note that Eulerian_tour and RMQ_reduction will have size 2*N -1
    // We will root the tree at 0

    void Eulerian_dfs(int p, int node, int depth){
        if (time_in[node] == -1) time_in[node] = ++t;
        if(Eulerian_tour.size() <= depth) Eulerian_tour.push_back(vector<int>());
        Depth[node] = depth;
        Eulerian_tour[depth].push_back(t);
        for (int i = 0; i < adj[node].size(); ++i) {
            if (adj[node][i] != p) {
                Eulerian_dfs(node, adj[node][i], depth + 1);
            }
        }
        time_out[node] = t++;
    }

    void build(int n){
        V = n;
        E = n - 1;
        int time = 0;
        adj.resize(V);
        Depth = time_in = time_out = vector<int> (V, -1);
        for(int i = 0; i < V; ++i){
            int x;
            cin >> x;
            if(x == -1) root = i;
            else{
                --x;
                adj[x].push_back(i);
            }
        }
        Eulerian_dfs(root, root, 0);
    }

    int query(int l, int k){
        int i = Depth[l] + k;
        if(i >= Eulerian_tour.size()) return 0;
        return lower_bound(Eulerian_tour[i].begin(), Eulerian_tour[i].end(), time_out[l]) -
                lower_bound(Eulerian_tour[i].begin(), Eulerian_tour[i].end(), time_in[l]);
    }

};

int main(){
    int n;
    cin >> n;
    Tree T;
    T.build(n);
    int m;
    cin >> m;
    while(m--){
        int l,k;
        cin >> l >> k;
        --l;
        cout << T.query(l,k) << endl;
    }

}
