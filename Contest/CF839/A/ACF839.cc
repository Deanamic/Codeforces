#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n , k;
	cin >> n >> k;
	int cur = 0;
	int give = 0;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		cur += x;
		int t = min(cur, 8);
		cur -= t;
		give += t;
		if(give >= k) return cout << i + 1 << endl, 0;
	}
	cout << -1 << endl;

}
