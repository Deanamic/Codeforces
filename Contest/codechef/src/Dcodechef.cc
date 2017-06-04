#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int n;

bool check(int k){
	int s = 0;
	int it = 0;
	bool inc = 1;
	while(it < n) {
		if(inc){
			if(v[it] > s) ++s;
			else s = v[it];
		}
		else{
			if(v[it] >= s) --s;
			else {
				s = v[it];
				inc = 1;
			}
		}
		if(s == k) {
			inc = 0;
			--s;
		}
		if(s == 0 and !inc) return true;
		++it;
	}
	return false;

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		v.resize(n);
		long long sz = 0;
		for(int i = 0; i < n; ++i){
			cin >> v[i];
			sz += v[i];
		}
		long long l = 1, r = (n+1)/2 + 1;
		while(l + 1 < r){
			int m = (l + r)/2;
			if(check(m)) l = m;
			else r = m;
		}
		//cerr << l << endl;
		cout << sz - l*l << endl;
	}

}
