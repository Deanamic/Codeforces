#include<bits/stdc++.h>
using namespace std;

long double area;
long double ht;

void rec(int c, long double b, long double h){
	if(c == 1) return;
	long double a1 = 1/ht;
	long double b1 = b + h/ht;
	long double c1 = -2*area;
	long double ans = h + (-b1 + sqrt((b1*b1) - (4*a1*c1))) / (2*a1);
	//ans = max(ans, (-b - sqrt(b*b + 8*b/h*area)) / -4*area);
	cout << ans  << ' ';
	rec(c-1, ans/ht, ans);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.setf(ios::fixed);
	cout.precision(14);
	int n;
	cin >> n >> ht;
	area = ht/(2.0*n);
	rec(n, 0.0, 0.0);
}
