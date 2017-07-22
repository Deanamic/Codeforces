#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long it = 0;
    long long last = 0, now = 1;
    long long aux;
    while(1){
        aux = last;
        last = now;
        now += aux;
        if(now > n) return cout << it-1 << endl, 0;
        ++it;
    }
}
