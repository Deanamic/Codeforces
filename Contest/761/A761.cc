#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    int r1 = max(a,b);
    int r2 = min(a,b);
    if(r1 - r2 > 1 or (a == 0 and b == 0)) cout << "NO" << endl;
    else cout << "YES" << endl;


}
