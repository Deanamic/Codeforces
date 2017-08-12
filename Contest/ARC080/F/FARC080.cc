#include<bits/stdc++.h>
using namespace std;


int pos[200010];
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
int s = 0;
struct obj {
	int t, x, y, s;

	bool operator < (const obj& o) const {
		if(o.s == s) return t > o.t;
		return x > o.x;
	}
};

priority_queue<obj> pq;

void getans(int l, int r, int p, int t, int s) {
	if(l + 1 >= r) return;
	int x = S[p].find(l,r);
	int px = pos[x];
	int y = S[p^1].find(px + 1, r);
	int py = pos[y];
	pq.push({t,x,y, s});
	getans(px + 1, py, p^1, t + 1, s);
	getans(l,px,p, t + 1, ++s);
	getans(py + 1, r, p, t + 1, ++s);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
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
	getans(0,n,0,0,0);
	while(pq.size()) {
		auto i = pq.top();
		pq.pop();
		cout << i.x << ' ' << i.y << ' ';
	}
	cout << endl;
}
