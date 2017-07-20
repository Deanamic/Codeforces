#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int v[n];
    for(int i = 0 ; i < n; ++i) cin >> v[i];
    for(int i = 0 ; i < n-1; ++i){
        if(v[i] < 0) return cout << "NO" << endl, 0;
        if(v[i] & 1) --v[i+1];
    }
	cout << (v[n-1] & 1 ? "NO" : "YES")<< endl;
}
