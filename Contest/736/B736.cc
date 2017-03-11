#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,n1,n2;
    cin >> n >> n1 >> n2;
    vector<double> vd(n);
    for(int i = 0; i < n; ++i){
        cin >> vd[i];
    }
    sort(vd.begin(), vd.end());
    double ans1,ans2;
    ans1 = ans2 = 0.0;
    int c1 = max(n1,n2);
    int c2 = min(n1,n2);
    int i = n-1;
    for(int j = 0; j < c2; ++j){
        ans2 +=  vd[i--];
    }
    for(int j = 0; j < c1; ++j){
        ans1 +=  vd[i--];
    }
    cout <<fixed << setprecision(8) <<  ans1/c1 + ans2/c2 << endl;

}
