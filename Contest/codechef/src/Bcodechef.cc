#include<bits/stdc++.h>
using namespace std;

char vc[2][510];
int n;

int dfs(int r, int c, int b){
	if(c == n or vc[r][c] == '.') return 0;
	if(b and vc[!r][c] == '#') return 1 + dfs(!r, c, 0);
	return 1 + dfs(r, c+1, 1);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		int cnt = 0;
		int l = n+1;
		for(int i = 0; i < n; ++i){
			cin >> vc[0][i];
			if(vc[0][i] == '#') {
				++cnt;
				l = min(i, l);
			}
		}
		for(int i = 0; i < n; ++i){
			cin >> vc[1][i];
			if(vc[1][i] == '#') {
				++cnt;
				l = min(i, l);
			}
		}
		if(dfs(0,l,1) == cnt or dfs(1,l,1) == cnt) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}
