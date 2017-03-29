#include<bits/stdc++.h>
using namespace std;

int main(){
    long long  b,q,l,m;
    cin >> b >> q >> l >> m;
    set<long long> bad;
    while(m--){
        long long x;
        cin >> x;
        bad.insert(x);
    }
    if(l < abs(b)) return cout << 0 << endl, 0;
    if(b == 0){
        if(bad.count(0))
            cout << 0 << endl;
        else
            cout << "inf" << endl;
        return 0;
    }
    if(q == 0){
        if(bad.count(0)){
            if(bad.count(b))
                cout << 0 << endl;
            else
                cout << 1 << endl;
        }
        else
            cout << "inf" << endl;
        return 0;
    }
    if(q == 1){
        if(bad.count(b))
            cout << 0 << endl;
        else
            cout << "inf" << endl;
        return 0;
    }
    if(q == -1){
        if(bad.count(b) and bad.count(-b) )
            cout << 0 << endl;
        else
            cout << "inf" << endl;
        return 0;
    }
    int ans = 0;
    while(abs(b) <= l){
        if(!bad.count(b)) ++ans;
        b *= q;
    }
    cout << ans << endl;

}
