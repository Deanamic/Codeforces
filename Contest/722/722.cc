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
/*
    intel codeforces
    http://codeforces.com/contest/722/problem/C
    problem C: destroying array
    given an array of nonnegative integers, say the maximum sum of continuous
    elements after eliminating the i-th value
*/

/*
    we will solve this problem by doing the problem in reverse, what is the
    maximum conitnuous subsum after adding the i-th element

*/
vector<int> pare;

int mfset(int a){
    if(pare[a] == -1) return -1;
    if(a == pare[a]) return a;
    return pare[a] = mfset(pare[a]);
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    pare = vector<int> (n,-1);
    vector<LL> sum(n,0);
    vector<LL> ans(n,0);
    vector<int> q(n);
    LL mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> q[i];
        --q[i];
    }
    for (int i = n-1; i >= 1; --i) {
       
        int x = q[i];
        pare[x] = x;
        if(x != n-1 and mfset(x+1) != -1){
            sum[x] += sum[pare[mfset(x+1)]];
            pare[mfset(x+1)] = x;
        }
        
        if(x != 0 and mfset(x-1) != -1){
            sum[x] += sum[pare[mfset(x-1)]];
            pare[mfset(x-1)] = x;
        }
        sum[x] += v[x];
        mx = max(sum[x],mx);
        ans[i-1] = mx;
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << '\n';
    }
}
