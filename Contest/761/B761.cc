#include <bits/stdc++.h>
using namespace std;

vector<int> a, b;
int n,L;

bool check(int c){
    vector<int> aux = b;
    for(int i = 0; i < n; ++i){
        aux[i] += c;
        aux[i] %= L;
    }
    sort(aux.begin(), aux.end());
    for(int i = 0; i < n; ++i){
        if(a[i] != aux[i]) return false;
    }
    return true;
}


int main(){

    cin >> n >> L;
    a = b = vector<int>(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }
    for(int i = 0; i < L; ++i){
        if(check(i)) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

}
