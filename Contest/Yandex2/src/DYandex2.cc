#include<bits/stdc++.h>
using namespace std;

int cnt = 0;
vector<vector<int> > grid(300, vector<int> (300, 0));

void add(int i, int j);

void overflow(int i, int j){
	grid[i][j] = 0;
	--cnt;
	add(i+1,j);
	add(i-1,j);
	add(i,j+1);
	add(i,j-1);
}

void add(int i, int j){
	++grid[i][j];
	if(grid[i][j] == 1) ++cnt;
	if(grid[i][j] == 5) overflow(i,j);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	while(n--){
		int x, y;
		cin >> x >> y;
		x += 120;
		y += 120;
		add(x,y);
		cout << cnt << endl;
	}

}
