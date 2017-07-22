#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,a,b,c;
    cin >> n >> a >> b >> c;
    if(n%4 == 0) cout << 0 << endl;
    else if(n%4 == 1) cout << min(a+b,min(c,3*a)) << endl;
    else if(n%4 == 2) cout << min(b,min(2*c,2*a)) << endl;
    else cout << min(a,b+c) << endl;
}
