#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
	map<long long, long long> mll;
    long long mx = n - 1;
    long long pref = 0;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        pref += x;
        ++mll[pref];
        mx=min(mx,n - mll[pref]);
    }
    cout << mx << '\n';
}
