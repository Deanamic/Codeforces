#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

int main (){
    int a,b,k,t;
    cin >> a >> b >> k >> t;
    t <<= 1;
    int dp[2*t*k + 1];
    int pref[2*t*k + 1];
    memset(dp, 0, sizeof dp);
    memset(pref, 0, sizeof pref);
    int offset = t*k;
    for(int i = -k; i <= k; ++i) {
        dp[offset + i] = 1;
    }
    for(int j = 1; j <= 2*k*t; ++j) pref[j] = (dp[j] + pref[j - 1]) % MOD;
    for(int i = 1; i < t; ++i) {
        for(int j = -(k*t); j <= (k*t); ++j){
            if(offset + j + k > 2*k*t) dp[offset + j] = pref[2*k*t];
            else dp[offset + j] = pref[offset + j + k];
            if(offset + j - k - 1 >= 0) dp[offset + j] -= pref[offset + j - k - 1];
            dp[offset + j] = (dp[offset + j]%MOD + MOD)%MOD;
        }
        pref[0] = dp[0];
        for(int j = 1; j <= 2*k*t; ++j) pref[j] = (dp[j] + pref[j - 1]) % MOD;
    }
    long long ans = 0;
    for(int i = offset + b-a+1; i <= 2*k*t; ++i) {
        ans += dp[i];
        ans %= MOD;
    }
    cout << ans << endl;
}
