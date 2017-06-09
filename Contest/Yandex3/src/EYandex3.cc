#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x1,y1,x2,y2;

	cin >> x1 >> y1 >> x2 >> y2;
		int dx = abs(x2 - x1), dy = abs(y2 - y1);
		int ans = 2*min(dx,dy);
		int go = max(dx - min(dx,dy), dy - min(dx,dy));
		//cout << go << endl;
		if(go == 0) cout << ans << endl;
		//else if(go == 1) cout << ans+1 << endl;
		else cout << ans + (go+1)/2 + (go/2)*3 << endl;

}
