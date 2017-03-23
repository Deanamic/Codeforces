#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    while(1){
        if(b == d) return cout << b << endl, 0;
        if(b < d) b += a;
        else d += c;
        if(b > 1e6) return cout << -1 << endl, 0;
    }
}
