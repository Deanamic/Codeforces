#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n,K;
    cin >> n >> K;
    vector<int> a(1001,0);
    for(int i = 0; i < K; ++i){
        int x;
        cin >> x;
        a[x] = 1;
    }
    unordered_map<int,int> dp;
    dp[0] = 1;
    for(int k = 0; k < 1000; ++k){
        unordered_map<int,int> tmp;
        for(auto i = dp.begin(); i != dp.end(); ++i){
            for(int j = 0; j < 1001; ++j){
                if(a[j]){
                    if(j+(i->first) < (n*(k+1) - 1000) or j+(i->first) > (n*(k+1) + 1000)) continue;
                    else{
                        tmp[j+(i->first)] = 1;
                        if(tmp.find(n*(k+1)) != tmp.end()) {
                            return cout << k+1 << endl, 0;
                        }
                    }
                }
            }

        }
        swap(dp,tmp);
    }
    cout << -1 << endl;
}
