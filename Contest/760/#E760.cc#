#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define POS(X,Y) *X.find_by_order(Y)
#define ORD(X,Y) X.order_of_key(Y)

vector<int> tree(100010,0);
int read(int idx){
    int sum = 0;
    while (idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx ,int val, int n){
    while (idx <= n){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int main(){
    int m;
    cin >> m;
    ordered_set<pair<int,int> > S;
    for(int i = 0; i < m; ++i){
        int t,p;
        cin >> t >>p;
        if(p == 1){
            int x;
            cin >> x;
            S.insert({t,x});
        }
        else{
            update(t,1,n);
        }


    }
}
