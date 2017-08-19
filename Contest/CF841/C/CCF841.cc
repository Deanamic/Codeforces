#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
vector<pair<int,int>>A, B;
int n;

int findpos(int l, int v) {
	int r = n;
	while(l + 1 < r) {
		int m = (l + r) >> 1;
		if(B[m].first < v) l = m;
		else r = m;
	}
	if(l >= n) return n;
	if(B[l].first >= v) return l;
	return l + 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	A = B = vector<pair<int,int>>(n);
	for(int i = 0; i < n; ++i){
		cin >> A[i].first;
		A[i].second = i;
	}
	for(int i = 0; i < n; ++i){
		cin >> B[i].first;
		B[i].second = i;
	}
	vector<int> ans(n);
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	vector<int> used(n,0);
	int l = 0;
	int i;
	for(i = 0; i < n; ++i){
		int p = findpos(l, A[i].first);
		if(p >= n) break;
		ans[B[p].second] = A[i].first;
		used[p] = 1;
		l = p + 1;
	}
	int it = n-1;
	int it1 = 0;
	while(it >= i) {
		while(used[it1]) ++it1;
		ans[B[it1].second] = A[it].first;
		it1++;
		--it;
	}
	for(int i : ans) cout << i << ' ';
	cout << endl;
}
