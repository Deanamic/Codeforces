#include<bits/stdc++.h>
using namespace std;


struct SegmentTree{
    vector<int> Seg;
	int n;

	void build(vector<int>& v, int m){
		n = m;
        Seg = vector<int> (4*n,1e6);
		build(v, 1, 0, n);
	}
	void build( vector<int>& v, int id,int left, int right){
		if(left + 1 >= right){
			Seg[id] = v[left];
			return;
		}
		int mid = (left + right)/2;
		build(v, id * 2, left, mid);
		build(v, id * 2 + 1, mid, right);
		Seg[id] = min(Seg[id*2],Seg[id*2 + 1]);
	}

	int find(int x, int y){
		return find(x, y, 1, 0, n);
	}
	int find(int x, int y, int id, int left, int right){
		if(left >= y or right <= x){
			return 1e6;
		}
		if(left >= x and right <= y){
			return Seg[id];
		}
		int mid = (left + right)/2;
		return min(find(x, y, 2*id, left, mid), find(x, y, 2*id + 1, mid, right));
	}
};
SegmentTree S[2];

int pos[200010];
int s = 0;
int parent[200010];
pair<int,int> E[200010];
int sz[200010];

void getans(int l, int r, int p, int par) {
	if(l + 1 >= r) return;
	int curNode = s++;
	sz[curNode] = 0;
	int x = S[p].find(l,r);
	int px = pos[x];
	int y = S[p^1].find(px + 1, r);
	int py = pos[y];

	E[curNode] = {x,y};
	if(par != -1) {
		parent[curNode] = par;
		sz[par]++;
	}
	getans(l, px, p, par);
	getans(px + 1, py, p^1, curNode);
	getans(py + 1, r, p, par);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	memset(parent, -1, sizeof parent);
	vector<int> odd(n, 1e6), even(n, 1e6);
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		pos[x] = i;
		if(i&1) even[i] = x;
		else odd[i] = x;
	}

	S[0].build(odd, n);
	S[1].build(even, n);
	getans(0,n,0,-1);

	int ans[n];
	priority_queue<pair<pair<int,int>,int>> pq;
	for(int i = 0; i < s; ++i) {
		if(sz[i] == 0) pq.push({E[i],i});
	}
	int last = n-1;
	while(pq.size()) {
		auto x = pq.top();
		pq.pop();
		ans[last--] = x.first.second;
		ans[last--] = x.first.first;

		int pare = parent[x.second];
		if(pare != -1) {
			sz[pare]--;
			if(sz[pare] == 0) pq.push({E[pare], pare});
		}
	}

	for(int i = 0; i < n; ++i) cout << ans[i] << ' ';
	cout << endl;
}
