#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i){
		cin >> b[i];
	}
	vector<int> ans(n);
	vector<int> app(n+1,0);
	vector<int> seq1(n+1,0),seq2(n+1,0);
	int a1, b1;
	for(int i = 0; i < n; ++i){
		seq1[a[i]]++;
		seq2[b[i]]++;
		if(seq1[a[i]] == 2) a1 = a[i];
		if(seq2[b[i]] == 2) b1 = b[i];
	}
	int c1,c2,p = -1;
	for(int i = 0; i < n; ++i){
		if(a[i] == b[i]) {
			if(!app[a[i]]) app[a[i]] = 1, ans[i] = a[i];
		}
		else{
			if(p != -1){
				if(app[a[i]] or app[b[p]] or a[p] != a1) {
					ans[i] = b[i];
					ans[p] = a[p];
				}
				else {
					ans[p] = b[p];
					ans[i] = a[i];
				}
			}
			else {
				p = i;
				c1 = a[i];
				c2 = b[i];
			}
		}
	}
	for(int i : ans) {
		if(i == 0) {
			int aux = 0;
			for(int j = 1; j <= n; ++j) if(!app[j]) aux = j;
			cout << aux <<' ';
		}
		else cout << i << ' ';
	}
	cout << endl;
}
