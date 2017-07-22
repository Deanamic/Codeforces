#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int ans = n;
    for(int i = 0; i < m; ++i){
        int x,y;
        cin >> x >> y;
        ans = min(ans,y-x+1);
    }
    cout << ans << endl;
    for(int i = 0; i < n; ++i){
        cout << i%ans << ' ';
    }
    cout << endl;
}
