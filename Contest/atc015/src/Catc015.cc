#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,q;
	cin >> n >> m >> q;
	vector<vector<int> > grid(n, vector<int> (m));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			char c;
			cin >> c;
			grid[i][j] = c - '0';
		}
	}
	vector<vector<int> > h(n, vector<int> (m,0)), v(n, vector<int> (m,0));
	for(int i = 0; i < n; ++i){
		int cont = 0;
		for(int j = 0; j < m; ++j){
			if(j) h[i][j] = h[i][j-1];
			if(grid[i][j] == 0) cont = 0;
			else {
				if(!cont){
					h[i][j]++;
					cont = 1;
				}
			}
		}
	}
	for(int i = 0; i < m; ++i){
		int cont = 1;
		for(int j = 0; j < n; ++j){
			if(j) h[j][i] = h[j-1][i];
			if(grid[j][i] == 0) cont = 0;
			else {
				if(!cont){
					v[j][i]++;
					cont = 1;
				}
			}
		}
	}
	while(q--){
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		--x1; --y1; --x2; --y2;
		long long ans = 0;
		ans += v[x2][y2];
		ans += h[x2][y2];
		ans += h[x1][y2];
		ans += v[x2][y1];
		if(x1 != 0){
			ans -= v[x1-1][y2];
			ans -= v[x1-1][y1];
		}
		if(y1 != 0){
			ans -= h[x2][y1 - 1];
			ans -= h[x1][y1 - 1];
		}
		cout << ans/2 << endl;

	}

}
