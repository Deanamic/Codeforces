#include <bits/stdc++.h>
using namespace std;

/* Segment Tree/ Interval Tree
 * Stores information in a Heap
 * Modification, lookup in O(logn)
 * Provides Tools to update intervals
 * All intervals are [ , )
*/

struct LazySegmentTree{
    vector<long long> Seg;
    vector<long long> lazy;
    vector<long long> M;
    vector<long long> Mlazy;
    long long n;

    void build(long long m){
		n = m;
        Mlazy = M = Seg = lazy = vector<long long> (16*n, 0);
	}

    long long find(long long x, long long y){
		return find(x, y, 1, 0, n);
	}
	long long find(long long x, long long y, long long id, long long left, long long right){
        if (lazy[id] != 0 or Mlazy[id] != 0) {
            M[id] = max(Seg[id] + Mlazy[id], M[id]);
            Seg[id] += lazy[id];
            if (x + 1 < y) {
                Mlazy[2*id] += Mlazy[id];
                Mlazy[2*id + 1] += Mlazy[id];
                lazy[2*id] += lazy[id];
                lazy[2*id + 1] += lazy[id];
            }
            lazy[id] = 0;
            Mlazy[id] = 0;
        }
		if(left >= y or right <= x){
			return -100000000000;
		}
		if(left >= x and right <= y){
			return M[id];
		}
		long long mid = (left + right)/2;
		return max(find(x, y, 2*id, left, mid),find(x, y, 2*id + 1, mid, right));
	}

    void updateinterval(long long p, long long x, long long y){
		updateinterval(p, 1, x, y, 0, n);
	}

    void updateinterval (long long p, long long id, long long x, long long y, long long left, long long right) {
        if (lazy[id] != 0 or Mlazy[id] != 0) {
            M[id] = max(Seg[id] + Mlazy[id], M[id]);
            Seg[id] += lazy[id];
            if (x + 1 < y) {
                Mlazy[2*id] += Mlazy[id];
                Mlazy[2*id + 1] += Mlazy[id];
                lazy[2*id] += lazy[id];
                lazy[2*id + 1] += lazy[id];
            }
            lazy[id] = 0;
            Mlazy[id] = 0;
        }
        if(left >= y or right <= x){
			return;
		}
		if(left >= x and right <= y){
            M[id] = max(Seg[id],M[id]);
            Seg[id] += p;
            M[id] = max(Seg[id],M[id]);
            if (x + 1 < y)  {
                lazy[2*id] += p;
                lazy[2*id + 1] += p;
                Mlazy[2*id] = max(Mlazy[2*id],lazy[2*id]);
                Mlazy[2*id + 1] = max(Mlazy[2*id + 1], lazy[2*id + 1]);
            }
            return;
        }
        long long mid = (left + right)/2;
        updateinterval (p, 2*id, x, y, left, mid);
        updateinterval (p, 2*id + 1, x, y, mid, right);
        Seg[id] = max(Seg[2*id],Seg[2*id + 1]);
        M[id] = max(Seg[id],M[id]);
    }
};

struct pers{
    int r,p,a,b,i;
    bool operator < (const pers& P) const {
        return r < P.r;
    }
};

int main(){
    int n;
    cin >> n;
    vector<pers> v(n);
    int mx = 0;
    for(long long i = 0; i < n; ++i){
        cin >> v[i].r >> v[i].p >> v[i].a >> v[i].b;
        v[i].i = i;
        --v[i].a;
        mx = max(mx,v[i].b);
    }
    vector<long long> ans(n);
    sort(v.begin(), v.end());
    LazySegmentTree L;
    L.build(mx+1);
    for(long long i = 0; i < n; ++i){
        ans[v[i].i] = L.find(v[i].a, v[i].b) + v[i].p;
        L.updateinterval(v[i].p, v[i].a, v[i].b);
    }
    for(long long i = 0; i < n; ++i){
        cout << ans[i] << '\n';
    }
}
