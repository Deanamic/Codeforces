#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    while(cin >> n >> m){
        vector<vector<int> > dp(n,vector<int> (n,1e9));
        for(int i = 0; i < n; ++i){
            dp[i][i] = 1;
        }
        for(int i = 0; i < m; ++i){
            int x,y;
            cin >> x >> y;
            dp[x][y] = 1;
        }
        for(int k = 0; k < n; ++k){
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < n; ++j){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(j) cout << ' ';
                cout <<  int(dp[i][j] != 1e9);
            }
            cout << endl;
        }
        for(int i = 0; i < 20; ++i){
            cout << '-';
        }cout << endl;
    }
}
