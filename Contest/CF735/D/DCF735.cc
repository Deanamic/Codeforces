#include <bits/stdc++.h>
using namespace std;

bool prime(int n){
    int i = 2;
    while(i * i <= n){
        if(n%i == 0) return false;
        ++i;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    if(prime(n)) cout << 1 << endl;
    else if(n%2 or !prime(n-2)){
        cout << 3 << endl;
    }else {
        cout << 2 << endl;
    }
}
