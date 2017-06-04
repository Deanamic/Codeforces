#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n , m;
	cin >> n >> m;
	int a[n];
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	while(m--){
		int l, r, x;
		cin >> l >> r >> x;
		--l; --x;
		int cnt = 0;
		for(int i = l; i < r; ++i){
			if (a[i] < a[x]) ++cnt;;
		}
		if(cnt == x-l) cout << "Yes" << '\n';
		else cout << "No" << '\n';
	}
}
