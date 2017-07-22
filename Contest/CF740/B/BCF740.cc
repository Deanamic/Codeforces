#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v(n+1);
    v[0] = 0;
    for(int i = 1; i <= n; ++i){
        cin >> v[i];
        v[i] += v[i-1];
    }
    int ans = 0;
    for(int i = 0; i < m; ++i){
        int x,y;
        cin >> x >> y;
        ans += max(0,v[y]-v[x-1]);
    }
    cout << ans << endl;
}
