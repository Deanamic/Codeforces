#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;
int sz;

vector<int> operator * (vector<int>& v, vector<int> y){
    vector<int> ans(sz);
    for(int i = 0; i < v.size(); ++i){
        for(int j = 0; j < y.size(); ++j){
            if(i+j-2000 >= sz) break;
            if(i+j-2000 < 0) continue;
            ans[i+j-2000] += (v[i]*y[j])%MOD;
        }
    }
    return ans;
}

void expvec(vector<int>& v, int t){
    if(t == 1) return v;
    if(t%2) v = v * expvec(v,t/2);
    expvec(v*v,t/2);
}

int main (){
    int a,b,k,t;
    cin >> a >> b >> k >> t;
    t *= 2;
    sz = 4*1000*t + 10;
    vector<int> g(4*1000*t + 10,0);
    for(int i = -k; i <= k; ++i){
        g[2000+i] = 1;
    }
    g = expvec(g,t);
    int ans = 0;
    for(int i = b-a + 1; i+2000 < sz ; ++i){
        ans += g[i+2000];
        ans %= MOD;
    }
    cout << ans << endl;


}
