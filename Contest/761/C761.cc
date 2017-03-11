#include <bits/stdc++.h>
using namespace std;

vector<string> v;
vector<int> ld,sd,nd;
const int INF = 1e8;
int dp[55][2][2][2];
int n,m;

int f(int i, int num, int l,int s){
    if(num == 1 and l == 1 and s == 1) return 0;
    if(i == n) return INF;
    if(dp[i][num][l][s] != -1) return dp[i][num][l][s];
    int ansn, ansl, anss;
    ansn = ansl = anss = INF;
    if(!num) ansn = f(i+1, 1, l, s) + nd[i];
    if(!l) ansl = f(i+1, num, 1, s) + ld[i];
    if(!s) anss = f(i+1, num, l, 1) + sd[i];
    return dp[i][num][l][s] = min(min(ansn,ansl),min(anss,f(i+1,num,l,s)));
}

int main(){

    cin >> n >> m;
    v = vector<string>(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    ld = sd = nd = vector<int>(n,INF);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 2; ++j){
            for(int k = 0; k < 2; ++k){
                for(int h = 0; h < 2; ++h){
                    dp[i][j][k][h] = -1;
                }
            }
        }
    }

    for(int i = 0; i < n; ++i){
        bool num,l,s;
        num = l = s = false;
        int p = 0;
        while(p <= m/2 and not(num and s and l)){
            if(isdigit(v[i][p]) or  (p and isdigit(v[i][m - p]))){
                if(not num) {
                    nd[i] = p;
                    num = true;
                }
            }
            if(isalpha(v[i][p]) or  (p and isalpha(v[i][m - p]))){
                if(not l) {
                    ld[i] = p;
                    l = true;
                }
            }
            if(not s and (not isdigit(v[i][p])) and (not isalpha(v[i][p]))) sd[i] = p;
            if(not s and  p and (not isdigit(v[i][m - p])) and (not isalpha(v[i][m - p]))) sd[i] = p;
            if(sd[i] != INF) s= true;
            ++p;
        }
    }
    cout << f(0,0,0,0) << endl;

}
