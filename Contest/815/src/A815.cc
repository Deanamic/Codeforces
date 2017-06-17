#include<bits/stdc++.h>
using namespace std;

int g[500][500];
int f[500];
int c[500];
int n,m;

long long tryr (int x) {
	f[0] = x;
	int t = x;
	for(int i = 0; i < m; ++i){
		t += c[i] = g[0][i] - f[0];
	}
	for(int i = 1; i < n; ++i){
		t += f[i] = g[i][0] - c[0];
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(g[i][j] != f[i] + c[j] or f[i] < 0 or c[j] < 0) return -1;
		}
	}
	return t;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	long long cnt = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> g[i][j];
			cnt += g[i][j];
		}
	}
	long long ans = -1;
	int it =0;
	for(int i = 0; i < 501; ++i){
		long long t = tryr(i);
		if(t != -1) {
			if(t < ans or ans == -1) {
				ans = t;
				it = i;
			}
		}
	}
	if(ans == -1) return cout << -1 << endl, 0;
	tryr(it);
	cout << ans << endl;

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < f[i]; ++j){
			cout << "row " << i+1 << endl;
		}
	}

	for(int i = 0; i < m; ++i){
		for(int j = 0; j < c[i]; ++j){
			cout << "col " << i+1 << endl;
		}
	}

}
