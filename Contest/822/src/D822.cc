#include<bits/stdc++.h>
using namespace std;

const int MXN = 5000001;
long long din[MXN];
long long gar[MXN];
int it;

inline long long calc(long long i){
	return (i*(i-1))/2;
}

long long comp(int x) {
	if(din[x] != -1) return din[x];
	long long mn = 1e18;
	for(int i = 2; i <= x; ++i) {
		if(x%i == 0) {
			long long c = comp(x/i) + (x/i)*calc(i);
			if(c < mn) {
				it = i, mn = c;
			}
		}
	}
	return din[x] = mn;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(din, -1, sizeof din);

	gar[0] = gar[1] = 1;
    memset( gar, -1, sizeof gar);
    for (long long i = 2; i < MXN; i++){
        if (gar[i] == -1){
			gar[i] = i;
            for (long long j = 2; j*i < MXN; j++) if(gar[i*j] == -1) gar[i*j] = i;
        }
    }

	din[1] = 0;
	din[2] = 1;
	for(int i = 3; i < MXN; ++i) {
		comp(i);
		if(it != gar[i]) return cout << i << endl, 0;
	}

}
