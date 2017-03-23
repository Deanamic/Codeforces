#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > m,dp,cnt;
int n;

int game(int p, int t){
    p %= n;
    //cout << t << ' ' << p << endl;
    if(dp[t][p] == p + n) return 2;
    if(dp[t][p] != 0 and dp[t][p] !=  2) return dp[t][p];
    dp[t][p] = p + n;
    int bc = 0;
    for(int i = cnt[t][p]++; i < m[t].size() and bc != 3; ++i){
        //cout << p + m[t][i] << endl;
        int a = game(p + m[t][i], 1-t);
        bc = max(a, bc);
    }
    return dp[t][p] = (4 - bc);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cnt = dp = vector<vector<int> > (2, vector<int>(n,0));
    dp[0][0] = 3;
    dp[1][0] = 3;
    //1 win
    //2 loop
    //3 lose
    //4 visiting

    m = vector<vector<int> >(2);

    int x;
    cin >> x;
    while(x--){
        int y;
        cin >> y;
        m[0].push_back(y);
    }
    cin >> x;
    while(x--){
        int y;
        cin >> y;
        m[1].push_back(y);
    }
    for(int i = 1; i < n; ++i){
        int a = game(i,0);
        if(a == 1) cout << "Win ";
        if(a == 2) cout << "Loop ";
        if(a == 3) cout << "Lose ";
    }
    cout << endl;
    for(int i = 1; i < n; ++i){
        int a = game(i,1);
        if(a == 1) cout << "Win ";
        if(a == 2) cout << "Loop ";
        if(a == 3) cout << "Lose ";
    }
        cout << endl;
}
