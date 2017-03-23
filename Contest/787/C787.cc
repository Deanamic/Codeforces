#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > m;
int dp[2][7010];
int n;
map<pair<int,int>, set<int> > mps;

int game(int p, int t){
    p %= n;
    if(dp[t][p] == p + n) return 2;
    if(dp[t][p] != 0 and dp[t][p] !=  2) return dp[t][p];
    dp[t][p] = p + n;
    int bc = 0;
    for(auto it = mps[{t,p}].begin(); it != mps[{t,p}].end();){
        int a = game(p + *it, 1-t);
        mps[{t,p}].erase(it);
        bc = max(a, bc);
    }
    return dp[t][p] = (4 - bc);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
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
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < n; ++j){
            for(int k = 0; k < m[i].size(); ++k){
                mps[{i,k}].insert(m[i][k]);
            }
        }
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
