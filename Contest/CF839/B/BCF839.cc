#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	int r4,r2,r1;
	r4 = n;
	r2 = 2*n;
	r1 = 0;
        priority_queue<int> pq;
	for(int i = 0; i < k; ++i){
		int x;
		cin >> x;
    pq.push(x);
  }
	while(pq.size()) {
	  int x = pq.top();
	  pq.pop();
		if(x >= 4) {
			if(r4) --r4;
			else if(r2 >= 2) r2 -= 2;
			else if(r2 and r1 >= 2) {
				--r2;
				r1 -= 2;
			}
			else if(r1 >= 4) r1 -= 4;
			else return cout << "NO" << endl, 0;
			x -= 4;
			pq.push(x);
		}
		else if(x == 3) {
		  if(r4) --r4;
			else if(r2 >= 2) r2 -= 2;
			else if(r2 and r1) --r2, --r1;
			else if(r1 >= 3) r1 -= 3;
			else return cout << "NO" << endl, 0;
			x -= 3;
    	pq.push(x);
		}
		else if(x == 2) {
		  if(r4) --r4, ++r1;
			else if(r2) --r2;
			else if(r1 >= 2) r1 -= 2;
			else return cout << "NO" << endl, 0;
			x -= 2;
			pq.push(x);
		}
		else if(x == 1) {
			if(r4) {
				--r4;
				++r2;
			}
			else if(r2) --r2;
			else if(r1) --r1;
			else return cout << "NO" << endl, 0;
			x -= 1;
			pq.push(x);
		}
	}
	cout << "YES" << endl;
}
