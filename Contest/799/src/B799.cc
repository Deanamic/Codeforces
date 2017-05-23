#include<bits/stdc++.h>
using namespace std;

struct shirt{
	long long p;
	int a;
	int b;
	int id;
	bool operator < (shirt s) const{
		return p < s.p;
	}
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<shirt> v(n);
	vector<int> used(n,0);
	for(int i = 0; i < n; ++i){
		cin >> v[i].p;
	}
	for(int i = 0; i < n; ++i){
		cin >> v[i].a; --v[i].a;
	}
	for(int i = 0; i < n; ++i){
		cin >> v[i].b; --v[i].b;
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < n; ++i){
		v[i].id = i;
	}
	vector<queue<int>> vq(3);
	for(int i = 0; i < n; ++i){
		if(v[i].a == v[i].b) {
			vq[v[i].a].push(v[i].id);
		}
		else{
			vq[v[i].a].push(v[i].id);
			vq[v[i].b].push(v[i].id);
		}
	}
	int m;
	cin >> m;
	while(m--){
		int c;
		cin >> c;
		--c;
		bool ans = 0;
		while(!ans){
			if(vq[c].size()){
				int p = vq[c].front();
				vq[c].pop();
				if(!used[p]){
					cout << v[p].p << ' ';
					used[p] = 1;
					ans = 1;
				}
			}
			else {
				ans = 1;
				cout << -1 << ' ';
			}
		}
	}
	cout << endl;

}
