#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        ans += (x+k-1)/k;
    }
    cout << (ans+1)/2 << endl;
    co
}
