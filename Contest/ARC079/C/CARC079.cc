#include<bits/stdc++.h>
using namespace std;

int can1[200010], can2[200010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(can1, 0, sizeof can1);
	memset(can2, 0, sizeof can2);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; ++i){
		int x,y;
		cin >> x >> y;
		int a = min(x, y);
		int b = max(x, y);
		if(a == 1) can1[b] = 1;
		if(b == n) can2[a] = 1;
	}
	if(can1[n] == 1) return cout << "POSSIBLE" << endl, 0;
	for(int i = 1; i < n; ++i) {
		if(can1[i] and can2[i]) return cout << "POSSIBLE" << endl, 0;
	}
	cout << "IMPOSSIBLE" << endl;
}
