#include <bits/stdc++.h>
using namespace std;

int main() {
     string s;
     cin >> s;
     int s1 = s.size();
     char c = 'a';
     int ans = 0;
     for(int i = 0; i < s1; ++i){
         ans += min(abs(c-s[i])%26,26 - abs(s[i]-c));
         c = s[i];
     }
     cout << ans << endl;
}
