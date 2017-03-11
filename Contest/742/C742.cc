#include <bits/stdc++.h>
using namespace std;

vector<long long> v;
vector<long long> t;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b){
    int temp = gcd(a, b);
    return temp ? (a / temp * b) : 0;
}

int main(){
    long long n;
    cin >> n;
    v = vector<long long>(n,-1);
    t = vector<long long>(n);
    for(long long i = 0; i < n; ++i){
        cin >> t[i]; --t[i];
    }
    long long cycle = -1;
    for(long long i = 0; i < n; ++i){
        if(v[i] == -1){
            long long j = i;
            long long sz = 0;
            while(v[j] == -1){
                v[j] = 0;
                j = t[j];
                ++sz;
            }
            if(j == i){
                if (cycle == -1) cycle = (sz%2 == 0 ? sz/2 : sz);
                else{
                    cycle = lcm(cycle,(sz%2 == 0 ? sz/2 : sz));
                }

            }
            else {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << cycle << endl;
}
