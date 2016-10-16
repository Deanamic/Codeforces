#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n; ++i){
        cin >> v[i];
    }
    for(int i = 0 ; i < n-1; ++i){
        if(v[i] < 0){
            cout << "NO\n";
            return 0;
        }

        v[i] -= 2*(v[i]/2);
        if(v[i]) --v[i+1];
    }
    if(v[n-1]%2 == 0){
        cout << "YES\n";
        return 0;
    }
    else{
        cout << "NO\n";
        return 0;
    }
}
