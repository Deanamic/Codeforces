#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    if( n == 2){
        cout << v[0] + v[1] << endl;
        return 0;
    }
    vector<vector<int> > dp(n,vector<int> (2));

    dp[n-1][0] = v[n-1];
    dp[n-1][1] = v[n-1];
    dp[n-2][0] = v[n-1] + v[n-2];
    dp[n-2][1] = max(abs(v[n-1] + v[n-2]), -v[n-1]);
    dp[n-3][0] = max(-v[n-1], v[n-1]+v[n-2]+v[n-3]);
    dp[n-3][1] = max(v[n-1]+v[n-2]+v[n-3],max(-dp[n-1][1],-dp[n-2][1]));
    sum = v[n-1]+v[n-2]+v[n-3];
    for(int i = n-4; i >= 0; --i){
        sum += v[i];
        dp[i][0] = max(sum,max(-dp[i+2][1],-dp[i+3][1]));
        dp[i][1] = max(sum,max(-dp[i+2][1],-dp[i+1][1]));
    }
    cout << dp[0][0] << endl;

}
