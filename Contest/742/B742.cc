#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    map<int,int> v;
    long long ans = 0;
    for(int i = 0; i < n; ++i){
        int y;
        cin >> y;
        ans += v[x^y];
        ++v[y];
    }
    cout << ans<< endl;

}
