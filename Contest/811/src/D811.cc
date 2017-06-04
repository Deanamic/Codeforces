#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > vis, v;
vector<int> ans;
int tx, ty;
int n , m;

bool dfs(int x, int y){
	vis[x][y] = 1;
	if(v[x][y] == -1) return false;
	if(v[x][y] == 1) return true;
	if(x > 1 and !vis[x-1][y] and dfs(x-1,y)) {
		ans.push_back(0);
		return 1;
	}
	if(x != n and !vis[x+1][y] and dfs(x+1,y)) {
		ans.push_back(1);
		return 1;
	}
	if(y > 1 and !vis[x][y-1] and dfs(x,y-1)) {
		ans.push_back(2);
		return 1;
	}
	if(y != m and !vis[x][y+1] and dfs(x,y+1)) {
		ans.push_back(3);
		return 1;
	}
	return 0;

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	v.resize(n+5, vector<int> (m+5,-1));
	vis.resize(n+5, vector<int> (m+5, 0));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			char  c;
			cin >> c;
			if(c == '.') v[i+1][j+1] = 0;
			if(c == '*') v[i+1][j+1] = -1;
			if(c == 'F') {
				v[i+1][j+1] = 1;
				tx = i+1;
				ty = j+1;
			}
		}
	}
	char s[] = {'U','D','L','R'};
	int ret = -1;
	int curx = 1, cury = 1;
	if(v[curx][cury+1] != -1) {
		for(int i = 1; ret == -1 and i <= m and v[1][i] != -1; ++i){
			if(v[2][i] != -1) ret = i;
		}
		cout << 'R' << endl;
		cin >> curx >> cury;
		if(v[curx][cury] == 1) return 0;

		if(curx == 1 and cury == 1) swap(s[2],s[3]);
		else {
			cout << 'L' << endl;
			cin >> curx >> cury;
			if(v[curx][cury] == 1) return 0;
		}

		while(cury != ret){
			cout << s[3] << endl;

			cin >> curx >> cury;
			if(v[curx][cury] == 1) return 0;
		}

		cout << 'D' << endl;
		int tmpx, tmpy;
		cin >> tmpx >> tmpy;
		if(tmpx == curx) swap(s[0],s[1]);
		curx = tmpx;
		cury = tmpy;
		if(v[curx][cury] == 1) return 0;

	}
	else{
		for(int i = 1; ret == -1 and i <= n and v[i][1] != -1; ++i){
			if(v[i][2] != -1) ret = i;
		}
		cout << 'D' << endl;
		cin >> curx >> cury;
		if(v[curx][cury] == 1) return 0;

		if(curx == 1 and cury == 1) swap(s[0],s[1]);
		while(curx != ret){
			cout << s[1] << endl;
			cin >> curx >> cury;
			if(v[curx][cury] == 1) return 0;
		}
		cout << 'R' << endl;

		int tmpx, tmpy;
		cin >> tmpx >> tmpy;
		if(tmpy == cury) swap(s[2],s[3]);
		curx = tmpx;
		cury = tmpy;
		if(v[curx][cury] == 1) return 0;
	}

	dfs(curx, cury);
	for(int i = ans.size() - 1; i >= 0; --i){
		cout << s[ans[i]] << endl;
		cin >> curx >> cury;
		if(v[curx][cury] == 1) return 0;
	}



}
