#include <bits/stdc++.h>
using namespace std;

bool good(int a, int b, int c){
	return a+b > c and a+c > b and b+c > a;
}

int main(){
    int T;
    cin >> T;
    for(int I = 1; I <= T; ++I){
        int N;
        cin >> N;
		cout << "Case #" << I << ": ";
		vector<long long> s(N);
		for(int i = 0; i < N; ++i){
			cin >> s[i];
		}
		sort(s.begin(), s.end());
		int i = 2;
		long long mn = 1e9;
		while(i < N){
			if(good(s[i],s[i-1],s[i-2])){
				int r = i-2;
				int l = -1;
				while(l + 1 < r){
					int m = (l+r)/2;
					if(s[m] > s[i]-s[i-1]) r = m;
					else l = m;
				}
				mn = min(mn, s[i] + s[i-1] + s[r]);
			}
			++i;
		}
		if(mn == 1e9) cout << "IMPOSSIBLE" << endl;
		else cout << mn << endl;
    }
}
