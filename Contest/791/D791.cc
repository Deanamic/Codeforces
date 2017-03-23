#include <bits/stdc++.h>
using namespace std;

int mod;

struct Tree {
    vector<vector<int> > adj;
    vector<vector<int> > adj_mod;
    vector<int> f;
    long long ANS = 0;
    int V, E;
    int LOG;
    int root = 0;
    int t = 0;
    vector<vector<int> > Eulerian_tour;
    vector<int> time_in, time_out;
    vector<int> Depth;
    vector<stack<int> > v_stack;
    vector<queue<int> > v_queue;
    // This vectors will save the ith value in the eulerian tour and its depth
    // And the first appereance of each node
    // Note that Eulerian_tour and RMQ_reduction will have size 2*N -1
    // We will root the tree at 0

    void Eulerian_dfs(int p, int node, int depth){
        if(depth < mod) v_queue[depth].push(node);
        if(v_stack[depth%mod].size())adj_mod[v_stack[depth%mod].top()].push_back(node);

        v_stack[depth%mod].push(node);

        if (time_in[node] == -1) time_in[node] = ++t;
        if(Eulerian_tour.size() <= depth) Eulerian_tour.push_back(vector<int>());
        Depth[node] = depth;
        Eulerian_tour[depth].push_back(t);
        for (int i = 0; i < adj[node].size(); ++i) {
            if (adj[node][i] != p) {
                Eulerian_dfs(node, adj[node][i], depth + 1);
                f[node] += f[adj[node][i]];
            }
        }
        time_out[node] = t++;
        v_stack[depth%mod].pop();
    }

    void build(int n){
        V = n;
        E = n - 1;
        int time = 0;
        adj.resize(V);
        adj_mod.resize(V);
        f.resize(V,1);
        v_stack.resize(mod);
        v_queue.resize(mod);
        Depth = time_in = time_out = vector<int> (V, -1);
        for(int i = 0; i < E; ++i){
            int x, y;
            cin >> x >> y;
            --x;
            --y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        Eulerian_dfs(root, root, 0);
    }

    int query(int l, int k){
        int i = Depth[l] + k;
        if(i >= Eulerian_tour.size()) return 0;
        return lower_bound(Eulerian_tour[i].begin(), Eulerian_tour[i].end(), time_out[l]) -
                lower_bound(Eulerian_tour[i].begin(), Eulerian_tour[i].end(), time_in[l]);
    }

    long long do_ans(int node){
        int sum = 0;
        for(int i = 1; i <= mod; ++i){
            sum += query(node, i);
        }
        for(int i = 0; i < adj_mod[node].size(); ++i){
            sum += do_ans(adj_mod[node][i]);
            sum += f[adj_mod[node][i]]-1;
        }
        cout << node+1 << ' ' << sum << endl;
        return ANS += sum;
    }

    long long get_ans(){
        for(int i = 0; i < mod; ++i){
            while(v_queue[i].size()){
                do_ans(v_queue[i].front());
                v_queue[i].pop();
            }
        }
        return ANS;
    }



};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n >> mod;
    Tree T;
    T.build(n);
    cout << T.get_ans() << endl;


}
