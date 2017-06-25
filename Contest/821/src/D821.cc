#include<bits/stdc++.h>
using namespace std;

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

int n, m, k;

struct state{
	int x, y, dir;
	bool operator <(const state& s) const {
		if(x != s.x) return x < s.x;
		if(y != s.y) return y < s.y;
		return dir < s.dir;
	}
};

vector<int> ver[10010], hor[10010];
map<state, int > cost;

bool exists(state p) {
	return cost.find(p) != cost.end();
}

int chk(int x, int y) {
	if(x == n) {
		auto it = lower_bound(ver[x].begin(), ver[x].end(), y);
		cout << ver[x].end() - it << endl;
		if(ver[x].end() - it == m - y + 1) return 0;
	}
	if(y == m) {
		auto it = lower_bound(hor[y].begin(), hor[y].end(), x);
		cout << hor[y].end() - it << endl;
		if(hor[y].end() - it == n - x + 1) return 0;
	}
	return 1;
}


int dfs(int x, int y, int dir) {
	if(x == n or y == m) return chk(x,y);
	if(exists({x,y,dir})) return cost[{x,y,dir}];
	int mn = 1e9;
	for(int i : hor[y]) {
		if(LEFT == dir and i < x) continue;
		if(RIGHT == dir and i > x) continue;
		if(i == x) continue;
		if(abs(x - i) == 1) mn = min(mn, dfs(i,y,(i > x? LEFT : RIGHT)));
		else mn = min(mn, 1 + dfs(i,y,(i > x? LEFT : RIGHT)));
	}

	for(int i : hor[y+1]) {
		if(i == x) continue;
		if(abs(x - i) == 1) mn = min(mn, dfs(i,y,(i > x? LEFT : RIGHT)));
		else mn = min(mn, 1 + dfs(i,y,(i > x? LEFT : RIGHT)));
	}

	if(y > 1) for(int i : hor[y-1]) {
		if(i == x) continue;
		if(abs(x - i) == 1) mn = min(mn, dfs(i,y,(i > x? LEFT : RIGHT)));
		else mn = min(mn, 1 + dfs(i,y,(i > x? LEFT : RIGHT)));
	}

	for(int i : ver[x]) {
		if(UP == dir and i < y) continue;
		if(DOWN == dir and i > y) continue;
		if(i == y) continue;
		if(abs(y - i) == 1) mn = min(mn, dfs(x,i,(i > y? UP : DOWN)));
		else mn = min(mn, 1 + dfs(x,i,(i > y? UP : DOWN)));
	}

	if(x > 1) for(int i : ver[x-1]) {
		if(i == y) continue;
		if(abs(y - i) == 1) mn = min(mn, dfs(x,i,(i > y? UP : DOWN)));
		else mn = min(mn, 1 + dfs(x,i,(i > y? UP : DOWN)));
	}

	for(int i : ver[x+1]) {
		if(i == y) continue;
		if(abs(y - i) == 1) mn = min(mn, dfs(x,i,(i > y? UP : DOWN)));
		else mn = min(mn, 1 + dfs(x,i,(i > y? UP : DOWN)));
	}
	return cost[{x,y,dir}] = mn;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	vector<pair<int,int> > mp(k);
	for(int i = 0; i < k; ++i) {
		int x,y;
		cin >> x >> y;
		ver[x].push_back(y);
		hor[y].push_back(x);
	}
	for(int i = 0; i <= m; ++i) sort(hor[i].begin(), hor[i].end());
	for(int i = 0; i <= n; ++i) sort(ver[i].begin(), ver[i].end());
	for(int i = 0; i < 4; ++i) cost[{0,0,i}] = 0;
	int ans = dfs(1,1,LEFT);
	if(ans >= 1e9) ans = -1;
	cout << ans << endl;


}
