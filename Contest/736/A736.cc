#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<char> vc(n);
    int g,t;
    for(int i = 0; i < n; ++i){
        cin >> vc[i];
        if(vc[i] == 'G') g = i;
        if(vc[i] == 'T') t = i;
    }
    if(g > t){
        swap(vc[g],vc[t]);
        swap(g,t);
    }
    int i = g+m;
    while(true){
        if(vc[i] == 'T') {
            cout << "YES\n";
            return 0;
        }
        if(i >= n or vc[i] == '#'){
            cout << "NO\n";
            return 0;
        }
        i += m;
    }
}
