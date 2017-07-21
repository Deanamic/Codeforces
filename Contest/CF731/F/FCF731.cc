#include <bits/stdc++.h>
using namespace std;

long long v[200010];
int pref[200010];
int used[200010];
int n;
long long sum = 0;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    memset(pref, 0, sizeof pref);
    memset(used, 0, sizeof used);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
        pref[v[i]]++;
        sum += v[i];
        used[v[i]] = 1;
    }
    if(used[1]) return cout << sum << endl, 0;
    for(int i = 1; i < 200010; ++i) pref[i] += pref[i-1];
    long long ans = 0;
    for(long long i = 2; i < 200010; ++i) {
        if(used[i]) {
            long long t = 0;
            for(int j = 1; j*i < 200010; ++j){
                int lt = j*i - 1;
                int gt = min(200009LL,(j+1)*i - 1);
                t += (pref[gt] - pref[lt]) * (j*i);
            }
            ans = max(ans, t);
        }
    }
    cout << ans << endl;
}
