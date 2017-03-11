#include<bits/stdc++.h>
using namespace std;

vector<string> t,h, ans;
unordered_map<string, int> m,ex;

int main(){
    int n;
    cin >> n;
    ans = t = h = vector<string> (n);
    for(int i = 0; i < n; ++i){
        cin >> t[i] >> h[i];
    }
    queue<int> q;
    for(int i = 0; i < n; ++i){
        string cmp = t[i].substr(0,3);
        string el = t[i].substr(0,2) + h[i][0];
        bool src = 1;
        for(int j = 0; src and j < n; ++j){
            if(i != j){
                if(cmp == t[j].substr(0,3)){
                    src = 0;
                    if (m.find(el) == m.end()) {
                        m[el] = 1;
                        ans[i] = el;
                    }
                    else{
                        return cout << "NO" << endl, 0;
                    }
                }
            }
        }
        if(src) q.push(i);
    }
    while(q.size()){
        int p = q.front(); q.pop();
        string el = t[p].substr(0,2) + h[p][0];
        string cmp = t[p].substr(0,3);
        if (m.find(c) == m.end()) {
            m[el] = 1;
            ans[p] = el;
        }
        if (m.find(el) == m.end()) {
            m[el] = 1;
            ans[p] = el;
        }
        else{
            return cout << "NO" << endl, 0;
        }
    }

    cout << "YES\n";
    for(int i = 0; i < n; ++i){
        cout << ans[i] << '\n';
    }
}
