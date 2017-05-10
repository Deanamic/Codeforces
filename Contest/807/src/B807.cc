#include<bits/stdc++.h>
using namespace std;


int good(int s, int ref){
	int j = (s/50)%475;
	for(int i = 0; i < 25; ++i){
		j = ((j*96)+42) % 475;
		if(j+26 == ref) return 1;
	}
	return 0;

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int p,x,y;
	cin >> p >> x >> y;
	int cur = x;
	queue<int> q;
	while(cur >= y){
		if(good(cur, p)) return cout << 0 << endl, 0;
		cur -= 50;
	}
	q.push(x);
	q.push(-1);
	int steps = 0;
	while(q.size()){
		int t = q.front(); q.pop();
		//cerr << t << endl;
		if(t == -1) {
			++steps;
			q.push(-1);
		}
		else{
			if(good(t, p)) return cout << steps << endl, 0;
			if((t - x)%100 == 0)q.push(t + 50);
			q.push(t + 100);
		}
	}
}
