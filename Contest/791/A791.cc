#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long a,b;
    cin >> a >> b;
    for(int i = 0; ; ++i){
        if (a > b) {
            cout << i << endl;
            return 0;
        }
        a *= 3;
        b *= 2;
    }
}
