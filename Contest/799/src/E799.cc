#include<bits/stdc++.h>
using namespace std;

long long aux, aux1;
struct patilla{
	long long c;
	int l;
};

bool cmp(const patilla& p, const patilla& p1) {
	long long a = p.c, b = p1.c;
	if(p.l == 3) a -= aux + aux1;
	else if(p.l == 2) a -= aux1;
	else if(p.l == 1) a -= aux;

	if(p1.l == 3) b -= aux + aux1;
	else if (p1.l == 2) b -= aux1;
	else if (p1.l) b -= aux;

	return a < b;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<patilla> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i].c;
		v[i].l = 0;
	}
	int x;
	bool rip = 0;
	cin >> x;
	if(x < k) rip = 1;
	while(x--){
		int y;
		cin >> y;
		--y;
		v[y].l += 1;
	}
	cin >> x;
	if(x < k) rip = 1;
	while(x--){
		int y;
		cin >> y;
		--y;
		v[y].l += 2;
	}
	if(rip) return cout << -1 << endl, 0;
	long long ans = 1e18;
	bool g = 0;
	long long l = -1, r = 1e15;
	while(l + 1 < r){
		aux = (l + r)/2;
		long long l1 = -1, r1 = 1e15;
		bool can = 0;
		while(l1 + 1 < r1){
			aux1 = (l1 + r1)/2;
			sort(v.begin(), v.end(), cmp);
			int cnta = 0, cntb = 0;
			long long ansaux = 0LL;
			for(int j = 0; j < m; ++j){
				if(v[j].l == 3){
					cnta++;
					cntb++;
				}
				else if(v[j].l == 2){
					cntb++;
				}
				else if(v[j].l) ++cnta;
				ansaux += v[j].c;
			}

			if(cnta >= k and cntb >= k){
				can = 1;
				g = 1;
				ans = min(ans, ansaux);
				r1 = aux1;
			}
			else if (cntb >= k){
				can = 1;
				r1 = aux1;
			}
			else {
				l1 = aux1;
			}
		}
		if(g){
			r = aux;
		}
		else {
			l = aux;
		}
	}
	cout << (!g ? -1 : ans) << endl;
}
