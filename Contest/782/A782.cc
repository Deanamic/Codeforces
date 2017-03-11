#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n,0);
    int t = 0,mx = 0;
    for(int i = 0; i < 2*n; ++i){
        int x;
        cin >> x;
        --x;
        if(v[x]) --t;
        else v[x] = 1, ++t;
        mx = max(mx,t);
    }
    cout << mx << endl;
}
