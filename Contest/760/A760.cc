#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,d;
    cin >> m >> d;
    if(m == 1 or m ==3 or m == 5 or m ==7 or m==8 or m == 10 or m == 12){
        cout << (36 + d)/7 << endl;
    }
    else if( m == 2){
        cout << (33 + d )/7 << endl;
    }else{
        cout << (35 + d)/7 << endl;
    }


}
