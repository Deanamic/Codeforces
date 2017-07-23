#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int A[n][m];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> A[i][j];
			--A[i][j];
		}
	}

	int ans = n;
	int gone[m];
	int nxt[n];
	int cnt[m];
	memset(nxt, 0, sizeof nxt);
	memset(gone, 0, sizeof gone);

	for(int i = 0; i < m; ++i){
		memset(cnt, 0, sizeof cnt);
		int mxcnt = 0;
		int mxit = 0;

		for(int j = 0; j < n; ++j){
			while(gone[A[j][nxt[j]]] == 1) nxt[j]++;
			if(++cnt[A[j][nxt[j]]] > mxcnt) {
				mxcnt = cnt[A[j][nxt[j]]];
				mxit = A[j][nxt[j]];
			}
		}

		ans = min(mxcnt, ans);
		gone[mxit] = 1;
	}
	cout << ans << endl;
}
