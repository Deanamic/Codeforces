#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,a,b;
	cin >> n >> a >> b;
	vector<int> v;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		v.push_back(x);
	}
	int it = 0;
	int num = 0;
	int cur = 0;
	int done = 0;
	int l = 0;
	vector<int> ans(n);
	while(l < n){
		++it;
		if(cur < n and it == v[cur])++cur, ++num;
		if(v[l] + b <= it or num >= a){
			int k = (num + 1)/2;
			for(int j = 0; j < k; ++j){
				ans[l++] = it;
				--num;
				++done;
			}
		}
	}
	for(int i : ans) cout << i << ' ';
	cout << endl;

}
