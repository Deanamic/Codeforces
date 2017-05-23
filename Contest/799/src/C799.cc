#include<bits/stdc++.h>
using namespace std;

struct SegmentTree{
    vector<int> Seg;
	  int n;

	void build( int m){
		n = m;
    Seg = vector<int> (4*n,-1e8);
	}

	int find(int x, int y){
		return find(x, y, 1, 0, n);
	}
	int find(int x, int y, int id, int left, int right){
		if(left >= y or right <= x){
			return -1e8;
		}
		if(left >= x and right <= y){
			return Seg[id];
		}
		int mid = (left + right)/2;
		return max(find(x, y, 2*id, left, mid), find(x, y, 2*id + 1, mid, right));
	}

	void update(int p, int new_value){
		update(p, new_value, 1, 0, n);
	}
	void update(int p, int new_value, int id, int left, int right){
		if(left + 1 >= right){
			Seg[id] = max(new_value,Seg[id]);
			return;
		}
		int mid = (left+right)/2;
		if(p < mid) update(p, new_value, 2*id, left, mid);
		else update(p, new_value, 2*id + 1, mid, right);
		Seg[id] = max(Seg[id*2],Seg[id*2 + 1]);
	}
};


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, co, di;
	cin >> n >> co >> di;
	SegmentTree C,D;
	C.build(100010);
	D.build(100010);
	int ans = 0;
	for(int i = 0; i < n; ++i){
		int b, p;
		char c;
		cin >> b >> p >> c;
		if(c == 'C'){
			if(p <= co){
				ans = max(ans, b + C.find(0, co-p+1));
				ans = max(ans, b + D.find(0, di+1));
				C.update(p, b);
			}
		}
		else{
			if(p <= di){
				ans = max(ans, b + D.find(0, di-p+1));
				ans = max(ans, b + C.find(0, co+1));
				D.update(p, b);
			}
		}
	}
	cout << ans << endl;
}
