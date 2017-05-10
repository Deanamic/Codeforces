#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> dp(n),v(n);
    for(int i = 0; i < n; ++ i){
        cin >> v[i];
    }
    long long ans = 0;
    long long cur = 0;
    for(int i = 0; i < n-1; ++i){
        cur += abs(a[i] - a[i+1]) * (i%2? -1 : 1);
        ans = max(cur,ans);
    }
    long long cur = 0;
    for(int i = 1; i < n-1; ++i){
        cur += abs(a[i] - a[i+1]) * (i%2? 1 : -1);
        ans = max(cur,ans);
    }
    cout << ans << endl;

}
