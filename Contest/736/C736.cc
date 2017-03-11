#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<long long> v(100);

    long long n;
    cin >> n;
    long long it = 0;
    long long last = 0, now = 1;
    long long aux;
    while(1){
        aux = last;
        last = now;
        now += aux;
        //cout << now << endl;
        if(now > n){
            cout << it-1 << endl;
            return 0;
        }
        ++it;

    }
}
