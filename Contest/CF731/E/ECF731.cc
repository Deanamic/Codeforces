#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int v[n];
  for(int i = 0; i < n; ++i) cin >> v[i];

  int p[n];
  p[0] = v[0];
  for(int i = 1; i < n; ++i) p[i] = v[i] + p[i-1];

  int dp[n];
  dp[n-1] = 0;
  int it = n-1;
  for(int i = n-2; i >= 0; --i) {
    if( p[i + 1] - dp[i + 1] > p[it] - dp[it]) it = i+1;
    dp[i] = p[it] - dp[it];
  }
  cout << dp[0] << endl;
}
