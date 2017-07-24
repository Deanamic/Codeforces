#include<bits/stdc++.h>
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
    vector<int> Eulerian_tour, RMQ_reduction, Ocurrence;
    SparseTable S;
	vector<int> d;
    // This vectors will save the ith value in the eulerian tour and its depth
    // And the first appereance of each node
    // Note that Eulerian_tour and RMQ_reduction will have size 2*N -1
    // We will root the tree at 0

    void Eulerian_dfs(int p, int node, int depth){
        if (Ocurrence[node] == -1) Ocurrence[node] = Eulerian_tour.size();
        Eulerian_tour.push_back(node);
        RMQ_reduction.push_back(depth);
		d[node] = depth;
        for (int i = 0; i < adj[node].size(); ++i) {
            if (adj[node][i] != p) {
                Eulerian_dfs(node, adj[node][i], depth + 1);
                Eulerian_tour.push_back(node);
                RMQ_reduction.push_back(depth);
            }
        }
    }

    void build(int n){
        V = n;
        E = n - 1;
        adj.resize(V);
		d.resize(V);
        Ocurrence = vector<int> (V, -1);
        for (int i = 1; i < V; ++i) {
            int x;
            cin >> x;
			--x;
            adj[x].push_back(i);
            adj[i].push_back(x);
        }
        Eulerian_dfs(0, 0, 0);
        S.build(RMQ_reduction.size(), RMQ_reduction);
    }

    int query(int l, int r){
        int L = min(Ocurrence[l], Ocurrence[r]);
        int R = max(Ocurrence[l], Ocurrence[r]);
        return Eulerian_tour[S.query(L, R, RMQ_reduction)];
    }

};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	Tree T;
	T.build(n);
	while(q--) {
		int a,b,c;
		cin >> a >> b >> c;
		--a; --b; --c;
		int ans = 0;
		int lca = T.query(a,b) ^ T.query(b,c) ^ T.query(a,c);
		ans = max(ans, T.d[c] + T.d[lca] - 2*T.d[T.query(lca,c)]);
		ans = max(ans, T.d[a] + T.d[lca] - 2*T.d[T.query(lca,a)]);
		ans = max(ans, T.d[b] + T.d[lca] - 2*T.d[T.query(lca,b)]);
		cout << ans + 1 << endl;
	}

}
