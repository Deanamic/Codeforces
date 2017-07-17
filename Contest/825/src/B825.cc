#include<bits/stdc++.h>
using namespace std;

char grid[12][12];

bool can(int x, int y) {
	if(grid[x][y] != '.') return false;

	int cnt = 0;
	for(int i = x - 1; i >= 0 and grid[i][y] == 'X'; --i) ++cnt;
	for(int i = x + 1; i < 10 and grid[i][y] == 'X'; ++i) ++cnt;
	if(cnt >= 4) return true;

	cnt = 0;
    for(int i = y - 1; i >= 0 and grid[x][i] == 'X'; --i) ++cnt;
    for(int i = y + 1; i < 10 and grid[x][i] == 'X'; ++i) ++cnt;
	if(cnt >= 4) return true;

	cnt = 0;
    for(int i = x - 1, j = y - 1; i >= 0 and j >= 0 and grid[i][j] == 'X'; --i, --j) ++cnt;
    for(int i = x + 1, j = y + 1; i < 10 and j < 10 and grid[i][j] == 'X'; ++i, ++j) ++cnt;
	if(cnt >= 4) return true;

	cnt = 0;
    for(int i = x - 1, j = y + 1; i >= 0 and j < 10 and grid[i][j] == 'X'; --i, ++j) ++cnt;
    for(int i = x + 1, j = y - 1; i < 10 and j >= 0 and grid[i][j] == 'X'; ++i, --j) ++cnt;
	if(cnt >= 4) return true;
	 return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i = 0; i < 10; ++i){
		for(int j = 0; j < 10; ++j){
			cin >> grid[i][j];
		}
	}

	for(int i = 0; i < 10 ; ++i){
		for(int j = 0; j < 10 ; ++j){
			if(can(i,j)) return cout << "YES" << endl, 0;
		}
	}
	cout << "NO" << endl;
}
