#include<bits/stdc++.h>
using namespace std;

long long n,l,a,b;
vector<int> v;

long long calc(int p){
	long long ans = 0;
	for(int i = 0; i < n; ++i){
		ans += abs(p - v[i]);
		p += l;
		if(p > b) return 1e15;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		cin >> n >> l >> a >> b;
		v.resize(n);
		for(int i = 0; i < n; ++i){
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		int le = a, r = b - n*l + 1;
		while(le + 3 < r){
			int p1 = le + (r-le)/3;
			int p2 = r - (r-le)/3;
			if(calc(p1)  < calc(p2)) {
				r = p2;
			}
			else {
				le = p1;
			}
		}
		cout << min(min(calc(le),calc(le+1)),min(calc(le+2),calc(le+3))) << endl;
	}
}
