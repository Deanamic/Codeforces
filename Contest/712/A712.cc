#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n),ans(n);
    //vector<int> odd(n+1,0), even(n+1,0);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    for(int i = n-1; i >= 0; --i){
        if(i != n-1){
            ans[i] = v[i] + v[i+1];
        }
        else{
            ans[i] = v[i];
        }
    }
    for(int i = 0; i < n; ++i){
        cout << ans[i] << ' ';
    }
    cout << endl;
}
