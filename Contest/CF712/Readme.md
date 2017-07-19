CONTEST Codeforces 712 Round 370 Div 2

[Contest link](http://codeforces.com/contest/370)  
[Editorial link](http://codeforces.com/blog/entry/47050)  
[Folder link](CF712)

- [x] Problem A  

- [x] Problem B  

- [x] Problem C  

- [x] Problem D  
We are given a game where p1 has a points, and p2 has b points. At each turn both players get [-k,k] points and they will play t turns. How many diferent games can be played such that p1 ends up with strcitly more points than p2.  
We can consider the same game with one player who has a-b points, and plays 2t turns.  
We could consider the naive dp[diff][turn] which would be O((kt)<sup>2</sup>) with O(k<sup>2</sup>t) to transition.  Lets see if this can be reduced.  
Indeed, using prefix sums we can easily see that we at each step we can obtain dp[i] = pref[i+k] - pref[i-k-1]. Which makes the transition in O(kt).  
We obtain a complexity of O(kt<sup>2</sup>).

- [ ] Problem E  
