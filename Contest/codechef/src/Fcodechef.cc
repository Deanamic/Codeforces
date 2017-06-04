#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		long long n,l,a,b;
		cin >> n >> l >> a >> b;
		vector<int> v(n);
		for(int i = 0; i < n; ++i){
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		long long ans1 = 0, ans2 = 0, ans3 = 0;
		int mid = n/2;
		int pos = v[mid];
		int last;

		last = b-l;
		for(int i = n-1; i >= 0; --i){
			ans1 += abs(last - v[i]);
			last -= l;
		} //more elements to the right


		last = a;
		for(int i = 0; i < n; ++i){
			ans2 += abs(last - v[i]);
			last += l;
		} //more elements to the left

		//mid one fits
		bool good = (pos >= a) and (pos+l <= b);
		last = pos - l;
		for(int i = (mid - 1); i >= 0; --i){
			if(last < a) good = 0;
			ans3 += abs(last - v[i]);
			last -= l;
		}
		last = pos + l;
		for(int i = (mid + 1); i < n; ++i){
			ans3 += abs(last - v[i]);
			last += l;
			if(last > b) good = 0;
		}

		if(!good) ans3 = 1e15;
		cout << min(ans3, min(ans1, ans2)) << endl;

	}
}
