#include<bits/stdc++.h>
using namespace std;


struct circle {
	long long x;
	long long y;
	long double r;
	bool operator < (const circle c) const {
		return r > c.r;
	}
};


vector<int> adj[1001];
vector<int> vis(1001, 0);
vector<circle> vc;
long double pi = 3.141592653589793238462643383;

bool inside(circle c1, circle c2){
	long double x1 = c1.x - c2.x;
	long double y1 = c1.y - c2.y;
	if(x1*x1 + y1*y1 <= c1.r*c1.r) return 1;
	return 0;
}

long double area(int i) {
	return vc[i].r*vc[i].r;
}

long double dfs(int x, int t){
	vis[x] = 1;
	long double ans = 0;
	if(t ==  -1) ans += area(x);
	else if(t == 0) ans -= area(x);
	else ans += area(x);
	for(int i : adj[x]) {
		if(t == -1) ans += dfs(i, 1);
		else ans += dfs(i, 1 - t);
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vc.resize(n);
	for(int i = 0; i < n; ++i){
		int x, y, r;
		cin >> vc[i].x >> vc[i].y >> vc[i].r;
	}
	sort(vc.begin(), vc.end());
	for(int i = 0; i < n; ++i){
		for(int j = i-1; j >= 0; --j){
			if(inside(vc[j], vc[i])) {
				adj[j].push_back(i);
				break;
			}
		}
	}
	long double ans = 0;
	for(int i = 0; i < n; ++i){
		if(vis[i] == 0) ans += dfs(i, -1);
	}
	cout << fixed << setprecision(15) << pi*ans << endl;
}
