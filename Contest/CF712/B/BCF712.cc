#include <bits/stdc++.h>
using namespace std;

int main (){
    string s;
    cin >> s;
    int x,y; x= y = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == 'R') ++x;
        if(s[i] == 'L') --x;
        if(s[i] == 'U') ++y;
        if(s[i] == 'D') --y;
    }
    x = abs(x);
    y = abs(y);
    if(s.size()%2) return cout << -1 << endl, 0;
    cout << (x + y)/2 << endl;
}
