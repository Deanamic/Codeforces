#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<long long> mn(n,1e9);
	multiset<long long> gl_min;
	vector<vector<long long>> adj(n, vector<long long> (n));
	for(int i = 0; i < n-1; ++i){
		for(int j = i+1; j < n; ++j){
			cin >> adj[i][j];
			adj[j][i] = adj[i][j];
			mn[i] = min(mn[i], adj[j][i]);
			mn[j] = min(mn[j], adj[j][i]);
		}
	}
	vector<long long> ans(n,1e15);
	for(int i = 0; i < n; ++i) gl_min.insert(mn[i]);
	for(int i = 0; i < n; ++i){
		ans[i] = min(ans[i], (n-1) * mn[i]);
		for(int j = 0; j < n; ++j){
			if(j != i){
				ans[i] = min(ans[i], adj[i][j] + (n-2) * mn[j]);
				long long aux = mn[j];
				gl_min.erase(aux);
				ans[i] = min(ans[i], 2*adj[i][j] + (n-3) * (*gl_min.begin()));
				gl_min.insert(aux);
			}
		}
	}
	for(int i = 0; i < n; ++i){
		cout<< ans[i] << endl;
	}


}
