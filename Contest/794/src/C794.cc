#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s1,s2;
	cin >> s1 >> s2;
	int n = s1.size();
	vector<char> v1(n), v2(n), ans(n);
	for(int i = 0; i < n; ++i){
		v1[i] = s1[i];
		v2[i] = s2[i];
	}
	sort(v1.begin(), v1.end());
	sort(v2.rbegin(), v2.rend());
	int i1,i2,f1,f2;
	int a1,a2;
	i1 = i2 = a1 = 0;
	a2 = n-1;
	f1 = (n+1)/2-1;
	f2 = n/2-1;
	for(int i = 0; i < n; ++i){
		if(i%2){
			if(v2[i2] > v1[i1]) ans[a1++] = v2[i2++];
			else{
				ans[a2--] = v2[f2--];
			}
		}
		else{
			if(v1[i1] < v2[i2]) ans[a1++] = v1[i1++]; //si mi mejor es mejor que el suyo al principio
			else {
				ans[a2--] = v1[f1--];
			}
		}
	}
	for(char c: ans) cout << c;
	cout << endl;
}
