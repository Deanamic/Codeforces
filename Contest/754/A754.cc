#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    bool zero = true;
    int sum = 0;
    int nonzero = -1;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
        if(v[i] != 0 and zero){
            zero = false;
            nonzero = i;
        }
        sum += v[i];
    }
    if(zero) cout << "NO\n";
    else {
        cout << "YES" << endl;
        if(sum){
            cout << 1 << endl;
            cout << "1 " << n << endl;
        }
        else{
            cout << 2 << endl;
            cout << "1 " << nonzero+1 << endl;
            cout << nonzero+2 << ' '<< n << endl;
        }
    }

}
