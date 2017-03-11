#include<bits/stdc++.h>
using namespace std;

int n;
vector<long double> pos, v;

long double check(long double m){
    long double ans = 0;
    for(int i = 0; i < n; ++i){
        ans = max(ans,abs(m-pos[i])/v[i]);
    }
    return ans;
}

int main(){

    cin >> n;

    v = pos = vector<long double>(n);
    for(int i = 0; i < n; ++i){
        cin >> pos[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    long double l = 0.0, r = 1e9 + 10;
    while(l + 1e-9 < r){
        long double m1 = l + (r-l)/2.5;
        long double m2 = r - (r-l)/2.5;
        if(check(m1) > check(m2)){
            l = m1;
        }
        else{
            r = m2;
        }
    }
    cout << fixed << setprecision(10) << check(l) << endl;

}
