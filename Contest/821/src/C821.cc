#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int sorted = 0;
	priority_queue<int> pq;
	stack<int> q;
	int ans = 0;
	int rm = n-1;
	for(int i = 0; i < 2*n; ++i) {
		string s;
		cin >> s;
		if(s == "add") {
			int x;
			cin >> x;
			x = n - x;
			if(pq.size() and x < pq.top()) sorted = 1;
			q.push(x);
			pq.push(x);
		}
		else {
			if(sorted) {
				if(q.size() and rm == q.top()) {
					q.pop();
				}
				else {
					++ans;
					sorted = 0;
					stack<int> tmp;
					swap(tmp,q);
				}
			}
			pq.pop();
			--rm;
		}
	}
	cout << ans << endl;

}
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);


}
