#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    int aux = n;
    int ans = 0;
    bool end = false;
    int i= 1,j = n;
    while (m > 0 and !end){
        m -= n;
        ++ans;
        if((k != aux and k != 1) and (i == k or j == k)){
            end = true;
        }else if((k == aux or k == 1) and i == k and j == k){
            end = true;
        }
        else{
            if(i != k){
                ++i; --n;
            }
            if(j != k){
                --j; --n;
            }
        }
    }
    // cout << ans << endl;
    // cout << m << endl;
    ans += m/aux;
    cout << ans << endl;

}
