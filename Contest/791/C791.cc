#include<bits/stdc++.h>
using namespace std;



string give(int i){
    string s = "";
    if(i >= 'z' - 'a'){
        s += 'a' + (i % ('z' - 'a'));
    }
    s += 'a' + (i % ( 'z' - 'a'));
    return s;
}
int main(){
    // for(int i = 0; i < 50; ++i){
    //     cout << give(i) << endl;
    // }
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<string> ans(n,"&");

    int last = 0;
    bool b = 0;
    vector<vector<int> > same(n, vector<int> (n,-1));
    for(int i = 0; i < n - m + 1; ++i){
        string s;
        cin >> s;
        if(s == "YES"){
            b = 1;
            for(int j = i; j < i+m; ++j){
                for(int k = i; k < j; ++k){
                    same[j][k] = 0;
                    same[k][j] = 0;
                }
            }
        }
        else{
            for(int j = i; j < i+m; ++j){
                for(int k = i; k < j; ++k){
                    if(same[j][k] == -1)
                        same[j][k] = same[k][j] = 1;
                }
            }
        }
    }
    // for(int j = 0; j < n; ++j){
    //     for(int k = 0; k < n; ++k){
    //         cout << same[j][k] << ' ';
    //     }
    //     cout << endl;
    // }
    if(!b){
        for(int i = 0; i < n; ++i){
            cout << "Aa" << ' ';
        }
        cout << endl;
        return 0;
    }
    ans[0] = 'a';
    int cnt = 1;
    for(int i = 1; i < n; ++i){
        if(ans[i] == "&"){
            for(int j = max(i-m+1,0); j < i; ++j){
                if(same[j][i] == 1){
                    ans[i] = ans[j];
                    for(int k = i+1; k < min(i+m,n); ++k){
                        if(same[i][k] == 0) same[j][k] = same[k][j] = 0;
                    }
                }
            }
        }
        if(ans[i] == "&") ans[i] = give(cnt++);

    }

    for(int i = 0; i < n; ++i){
       cout << 'A' << ans[i] << ' ';
    }
    cout << endl;






}
