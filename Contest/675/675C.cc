//C++ Template

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
typedef map<int,int>::iterator ITmii;

#define EPS 1e-9
#define FOR1(x,y,z) for( int x = y; x < z ; ++x)
#define FOR(x,y) FOR1(x,0,y)
#define FOR2(x,y) for(int x = y; x >= 0; --x)
#define PB push_back
#define ALL(X) (X).begin(), (X).end()
#define SORT(X) sort(ALL(X))
#define SIZE(X) ((int)(X).size())

//------------------------------------------------------------------
map<LL,LL> mll;

int main(){
    int n;
    cin >> n;
    LL mx = n - 1;
    LL pref = 0;
    FOR(i,n){
        int x;
        cin >> x;
        pref += x;
        ++mll[pref];
        mx=min(mx,n - mll[pref]);
    }
    cout << mx << '\n';
}
