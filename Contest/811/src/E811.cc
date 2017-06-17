#include<bits/stdc++.h>
using namespace std;

struct Node {
	int L[10], R[10];
	int l, r;
	int comp = 0;
};

int grid[11][100010];
using pii = pair<int,int>;

struct SegmentTree {
	int n,m;
	Node S[400050];
	pii mfset[11][100010];

	pii pare(pii i) {
		if(mfset[i.first][i.second].first == -1) return i;
		return mfset[i.first][i.second] = pare(mfset[i.first][i.second]);
	}

	void mergepare(pii i, pii j) {
		pii p1 = pare(i), p2 = pare(j);
		mfset[p1.first][p1.second] = p2;
	}

	void fill(int id, int l, int sz) {
		S[id].comp = sz;
		S[id].l = S[id].r = l;
		for(int i = 0; i < sz; ++i){
			S[id].L[i] = S[id].R[i] = grid[i][l];
			if(i and S[id].L[i] == S[id].L[i-1]) {
				--S[id].comp;
				mergepare({i,l},{i-1,l});
			}
		}
	}

	void merge(int id, int sz) {
		S[id].comp = S[id << 1].comp + S[(id << 1) + 1].comp;
		S[id].l = S[id << 1].l;
		S[id].r = S[(id << 1) + 1].r;
		for(int i = 0; i < sz; ++i){
			S[id].L[i] = S[id<<1].L[i];
			S[id].R[i] = S[(id<<1) + 1].R[i];
			if(S[id<<1].R[id] == S[(id<<1) + 1].L[i] and pare({i,S[id<<1].r}) != pare({i,S[id<<1 + 1].l})) {
				--S[id].comp;
				mergepare({i,S[id<<1].r},{i,S[id<<1 + 1].l});
			}
		}
	}

	void build(int _n, int _m) {
		memset(mfset, -1, sizeof mfset);
		n = _n;
		m = _m;
		build(1, 0, m);
	}

	void build(int id, int l, int r) {
		if(l + 1 == r) {
			fill(id, l, n);
			return;
		}
		build(id << 1, l, (l+r) >> 1);
		build((id << 1) + 1, (l+r) >> 1, r);
		merge(id, n);
	}

	Node mergecnt(Node n1, Node n2) {
		Node ans;
		ans.comp = n1.comp + n2.comp;
		ans.l = n1.l;
		ans.r = n2.r;
		set<pair<int,int> > sii;
		for(int i = 0; i < n; ++i){
			ans.L[i] = n1.L[i];
			ans.R[i] = n2.R[i];
			sii.insert(pare(n1.r, i));
		}
		for(int i = 0; i < n; ++i){
			if(grid[n1.r][i] == grid[n1.r + 1][i]) {
				if(sii.count(pare(n1.r+1, i)) {
					--ans.comp;
				}
			}
		}

	}

	Node query(int id, int l, int r, int x, int y) {
		if(r <= x or l >= y) return {{0},{0},0,0,0};
		if(r <= y and l >= x) return S[id];
		return mergecnt(query(id << 1, l, (l + r) >> 1, x, y), query((id << 1) + 1, (l + r) >> 1, r, x, y));
	}









};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, q;
	cin >> n >> m >> q;

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> grid[i][j];
		}
	}
}
