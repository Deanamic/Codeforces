#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int H,W;
	cin >> H >> W;
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	int ans[H][W];
	int it = 0;
	for(int i = 0; i < H; ++i){
		for(int j = 0; j < W; ++j){
			while(a[it] == 0) it++;
			int k = j;
			if(i&1) k = W-j-1;
			ans[i][k] = it;
			--a[it];
		}
	}
	for(int i = 0; i < H; ++i){
		for(int j = 0; j < W; ++j){
			cout << ans[i][j] + 1<< ' ';
		}
		cout << endl;
	}
}
