#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> fact(
  string s;
  cin >> s;
  vector<int> br(s.size(),0);
  br[0] = (s[0] == '('? 1 : 0);
  for(int i = 1; i < s.size(); ++i){
    br[i] = br[i-1] + (s[i] == '('? 1 : 0);
  }
  long long ans = 0;
  for(int i = 0; i < s.size(); ++i){
    if(s[i] == '('){
      ans += 
    }
  }


}
