#include <bits/stdc++.h>
using namespace std;

int main(){
	long long a,b,c,d,n;
	cin >> n >> a >> b >> c >> d;
	cout << max(0LL,n*(n-abs(d-a)-abs(b-c))) << '\n';
}
