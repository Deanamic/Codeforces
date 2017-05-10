#include<bits/stdc++.h>
using namespace std;

#define CR 1
#define CB 2
#define CY 3

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for(int I = 1; I <= T; ++I){
		cout << "Case #" << I  << ": ";
		cerr << I << endl;
		int n,r,o,y,g,b,v;
		cin >> n >> r >> o >> y >> g >> b >> v;
		if(g > r or o > b or v > y) cout << "IMPOSSIBLE";
		else{
			if(g == r and g+r == n){
				for(int i = 0; i < n; ++i){
					cout << (i%2 ? 'G' : 'R');
				}
			}
			else if(o == b and o+b == n){
				for(int i = 0; i < n; ++i){
					cout << (i%2 ? 'O' : 'B');
				}
			}
			else if(y == v and v+v == n){
				for(int i = 0; i < n; ++i){
					cout << (i%2 ? 'Y' : 'V');
				}
			}
			else{
				if(o) b -= o;
				if(v) y -= v;
				if(g) r -= g;

				if(b < 0 or y < 0 or g < 0) cout << "IMPOSSIBLE";
				else if(y+b < r or r+y < b or b+r < y) cout << "IMPOSSIBLE";
				else {
					if(o) b -= 1;
					if(v) y -= 1;
					if(g) r -= 1;
					string s1,s2,s3,aux;
					s1 = s2 = s3 = aux = "";
					if(o){
						s1 += 'B';
						for(int i = 0; i < 2*o; ++i){
							s1 += (i%2 ? 'B' : 'O');
						}
					}
					if(v){
						s2 += 'Y';
						for(int i = 0; i < 2*v; ++i){
							s2 += (i%2 ? 'Y' : 'V');
						}
					}
					if(g){
						s3 += 'R';
						for(int i = 0; i < 2*g; ++i){
							s3 += (i%2 ? 'R' : 'G');
						}
					}
					int cur;
					//cerr << I << ' '  << b << ' ' << y << ' ' << r << endl;
					if(b >= y and b >= r) {
						cur = CB;
						aux += 'B';
						--b;
					}
					else if(y >= b and y >= r) {
						cur = CY;
						aux += 'Y';
						--y;
					}
					else {
						cur = CR;
						aux += 'R';
						--r;
					}
					if(I == 40) cerr << I << ' '  << b << ' ' << y << ' ' << r << endl;
					while(b or y or r){

						if(cur == CR){
							if(b >= y) {
								aux += 'B';
								cur = CB;
								--b;
							}
							else{
								aux += 'Y';
								cur = CY;
								--y;
							}
						}
						else if(cur == CB){
							if(r > y) {
								aux += 'R';
								cur = CR;
								--r;
							}
							else{
								aux += 'Y';
								cur = CY;
								--y;
							}
						}
						else if(cur == CY){
							if(b >= r) {
								aux += 'B';
								cur = CB;
								--b;
							}
							else{
								aux += 'R';
								cur = CR;
								--r;
							}
						}
					}
					if(aux[0] != 'B'){
						if(aux[aux.size()-1] == 'R') cout << s1 << aux << s2 << s3;
						else{
							reverse(aux.begin(), aux.end());
							cout << aux << s1 << s2 << s3;
						}
					}
					else {
						if(aux[aux.size()-1] == 'R'){
							reverse(aux.begin(), aux.end());
							cout << s1 << s2 << aux << s3;
						}
						else cout << s1 << s2 << aux << s3;
					}
				}
			}
		}
		cout << endl;
	}
}
