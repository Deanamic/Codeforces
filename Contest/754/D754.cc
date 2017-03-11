#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define POS(X, Y) *X.find_by_order(Y)
#define ORD(X, Y) X.order_of_key(Y)

struct bracket {
    int p;
    bool open;
    int id;

    bool operator<(const bracket& P) const {
        if (p != P.p) return p > P.p;
        else return open;
    }
};

ordered_set<bracket> S;


int main(){
    int n, k;
    cin >> n >> k;
    vector<pair<int, int> > v(n);
    priority_queue<bracket> pq;
    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        v[i] = {x,y};
        pq.push({ v[i].first, 1, i });
        pq.push({ v[i].second, 0, i });
    }
    int mx = -1;
    int op, cl;
    while (!pq.empty()) {
        bracket b = pq.top(); pq.pop();
        if (b.open) {
            S.insert(b);
        } else {
            S.erase(S.find({ v[b.id].first, 1, b.id }));
            if (S.size() >= k - 1) {
                bracket br = POS(S, S.size() - k + 1);
                if (v[b.id].first > br.p) {
                    if (mx < (b.p - v[b.id].first)) {
                        mx = b.p - v[b.id].first;
                        cl = b.id;
                        op = b.id;
                    }
                } else {
                    if (mx < (b.p - br.p)) {
                        mx = b.p - br.p;
                        cl = b.id;
                        op = br.id;
                    }
                }
            }
        }
    }
    if (mx == -1) {
        cout << 0 << endl;
        for (int i = 0; i < k; ++i) {
            cout << i + 1 << ' ';
        }
        cout << endl;
    } else {
        cout << mx + 1 << endl;
        cout << op + 1;
        int cnt = 1;
        if (cl != op) {
            cout << ' ' << cl + 1;
            ++cnt;
        }
        for (int i = 0; i < n and cnt < k; ++i) {
            if (v[i].first <= v[op].first and v[i].second >= v[cl].second and i != cl and i != op) {
                cout << ' ' << i + 1;
                ++cnt;
            }
        }
        cout << endl;

    }

} // main
