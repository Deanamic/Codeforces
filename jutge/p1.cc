#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VE;
typedef vector<VE> VVE;

int main(){
    int N, T;
    while(cin >> N >> T){
        VVE c(N);
        VVE e(N);
        VVE dp(2,VE(T+1,-1));
        dp[0][0] = 0;
        cin.ignore();
        for(int i = 0; i < N; ++i){
            c[i].push_back(0);
            e[i].push_back(0);
            string s;
            getline(cin,s);
            istringstream inp(s);
            int x,y;
            while(inp >> x >> y){
                c[i].push_back(x);
                e[i].push_back(y);
            }
        }
        int ans= 0;
        int I = 0;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < T+1; ++j){
                if(dp[I][j] != -1){
                    for(int k = 0; k < c[i].size(); ++k){
                        if(c[i][k] + j < T+1){
                            dp[I^1][c[i][k] + j] = max(dp[I^1][c[i][k] + j], dp[I][j] + e[i][k]);
                        }
                    }
                }
                dp[I][j] = -1;
            }
            I = 1-I;
        }
        for(int j = 0; j < T+1; ++j) ans = max(ans, dp[I][j]);
        cout << ans << endl;
    }
}
