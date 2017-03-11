#include <bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;

bool comp(ii a,ii b){
    if (a.second-a.first < b.second-b.first) return true;
    if (a.second-a.first > b.second-b.first) return false;
    return a.first < b.first;
}


int main(){
    int n,m;
    cin >> n >> m;
    vector<ii> v(m);
    vector<int> mark(n,-1);
    vector<int> arr(n,0);
    int ans = n;
    for(int i = 0; i < m; ++i){
        cin >> v[i].first >> v[i].second; --v[i].first; --v[i].second;
        ans = min(ans,v[i].second - v[i].first + 1);
        //cout << ans << endl;
    }
    sort(v.begin(),v.end(),comp);
    for(int i = 0; i < m; ++i){
        int k = 0;
        if(mark[v[i].second] != -1) k = arr[v[i].second] + 1;
        int low; int pos; bool inrange = false;
        for(int j = v[i].first; j <= v[i].second; ++j){
            if(mark[j] != -1){
                low = arr[j];
                pos = j = mark[j];
                inrange = true;
            }
            else{
                if(inrange){
                    if(k >= low){
                        k = arr[pos]+1;
                        inrange = 0;
                    }
                }
                mark[j] = v[i].second;
                arr[j] = k;
                ++k;
            }
        }
    }
    cout << ans << endl;
    for(int i = 0; i < n; ++i){
        cout << arr[i] << ' ';
    }
    cout << endl;


}
