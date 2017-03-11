#include <bits/stdc++.h>
using namespace std;
vector<vector<char> > v;

char pos(int i,int j){
    if(i >= 0 and i < 4 and j >= 0 and j < 4) return v[i][j];
    return '.';
}

bool check(int i, int j){
    if(pos(i-1,j-1) == 'x' and pos(i-2,j-2) == 'x') return 1;
    if(pos(i-1,j) == 'x' and pos(i-2,j) == 'x') return 1;
    if(pos(i,j-1) == 'x' and pos(i,j-2) == 'x') return 1;
    if(pos(i+1,j+1) == 'x' and pos(i+2,j+2) == 'x') return 1;
    if(pos(i,j+1) == 'x' and pos(i,j+2) == 'x') return 1;
    if(pos(i+1,j) == 'x' and pos(i+2,j) == 'x') return 1;

    if(pos(i+1,j-1) == 'x' and pos(i+2,j-2) == 'x') return 1;

    if(pos(i-1,j+1) == 'x' and pos(i-2,j+2) == 'x') return 1;

    if(pos(i-1,j-1) == 'x' and pos(i+1,j+1) == 'x') return 1;
    if(pos(i-1,j) == 'x' and pos(i+1,j) == 'x') return 1;
    if(pos(i,j-1) == 'x' and pos(i,j+1) == 'x') return 1;
    if(pos(i-1,j+1) == 'x' and pos(i+1,j-1) == 'x') return 1;

    return 0;
}

int main(){
    v = vector<vector<char> >(4,vector<char> (4));
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            cin >> v[i][j];
        }
    }
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            if(v[i][j] == '.' and check(i,j)){
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";


}
