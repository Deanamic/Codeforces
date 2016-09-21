//C++ Template

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<LL> VI;
typedef vector<VI> VVI;
typedef map<LL,LL>::iterator ITmii;

#define EPS 1e-9
#define FOR1(x,y,z) for( LL x = y; x < z ; ++x)
#define FOR(x,y) FOR1(x,0,y)
#define FOR2(x,y) for(LL x = y; x >= 0; --x)
#define PB push_back
#define ALL(X) (X).begin(), (X).end()
#define SORT(X) sort(ALL(X))
#define SIZE(X) ((LL)(X).size())

//------------------------------------------------------------------
VI s, a;
LL ans;
const LL INF = 1e16;
LL n;

LL find(LL id, LL l, LL r, LL x, LL y){
	LL mid = (l+r)/2;
	if(l >=x and r <= y) return s[id];
	else if(l > y or r < x) return INF;
	else return min(find(2*id,l,mid,x,y),find(2*id+1,mid+1,r,x,y));
}

void build(LL id,LL l, LL r){ //inicializado a 1, 0, n
	if(l == r){
		if(l == n-1) s[id]=0;
		else {
			s[id] = n - a[l] - l - 1 + find(1,0,n-1,l+1,l+a[l]);
			ans += s[id]; 
		}
		return;
	}
	LL mid = (l+r)/2;
	build(2*id+1,mid+1,r);
	build(2*id ,l,mid);
	s[id] = min(s[2*id],s[2*id+1]);
}



int main(){

	cin >> n;
	ans = (n*(n-1))/2;
	a = VI(n);
	s = VI(4*n,INF);
	FOR(i,n-1){
		LL x;
		cin >> x;
		--x;
		a[i] = x-i;
	}
	build(1,0,n-1);
	cout << ans << '\n';
}
