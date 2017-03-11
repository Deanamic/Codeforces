#include <bits/stdc++.h>
using namespace std;

int n,l,r;
int main(){
    cin >> n >> l >> r;
    vector<pair<int, int> > v(n);
    vector<int> order(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i].second;
    }
    for(int i = 0; i < n; ++i){
        cin >> v[i].first;
        order[i] = v[i].first;
    }
    sort(v.begin(), v.end());
    vector<int> ans(n);
    for(int i = n-1; i > 0; --i){
        if(v[i].second >= v[i-1].second) ans[i] = v[i].second - v[i-1].second + 1;
        else ans[i] = 0;
    }
    vector<int> p(n);
    p[0] = l;
    for(int i = 1; i < n; ++i){
        p[i] = p[i-1] + ans[i];
        if(p[i] > r){
            cout << -1 << endl;
            return 0;
        }
    }

    for(int i = 0; i < n; ++i){
        cout << p[order[i]-1] << ' ';
    }
    cout << endl;

}
