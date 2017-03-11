#include <bits/stdc++.h>
using namespace std;

vector<int> v,visit;

void dfs(int i){
    visit[i] = 1;
    if(visit[v[i]] == 0) dfs(v[i]);
}
int main(){
    int n;
    cin >> n;
    v = vector<int>(n);
    visit =vector<int>(n,0);
    int turn = 0;
    for(int i = 0; i < n; ++i){
        cin >> v[i];
        --v[i];
    }
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        if(x == 1){
            ++turn;
        }
    }
    int cycle = 0;
    for(int i = 0; i < n; ++i){
        if(visit[i] == 0){
            dfs(i);
            ++cycle;
        }
    }
    int ans = 0;
    if(cycle != 1) ans = cycle;
    if(turn%2 == 0) ++ans;
    cout << ans << endl;

}
