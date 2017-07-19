#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int v[n+1];
    for(int i = 0; i < n; ++i) cin >> v[i];
    v[n] = 0;
    for(int i = 0; i < n; ++i) cout << v[i] + v[i+1] << ' ';
    cout << endl;
}
