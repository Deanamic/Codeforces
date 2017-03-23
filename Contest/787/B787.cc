#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        bool end = 1;
        vector<int> v(n,0);
        int x;
        cin >> x;
        while(x--){
            int y;
            cin >> y;
            if(y > 0){
                --y;
                if(v[y] == 2) end = 0;
                v[y] = 1;
            }
            else{
                y = -y;
                --y;
                if(v[y] == 1) end = 0;
                v[y] = 2;
            }
        }
        if(end) return cout << "YES" << endl, 0;
    }
    cout << "NO" << endl;
}
