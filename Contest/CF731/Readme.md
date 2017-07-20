CONTEST Codeforces 712 Round 370 Div 2

[Contest link](http://codeforces.com/contest/370)  
[Editorial link](http://codeforces.com/blog/entry/47050)  
[Folder link](CF712)

- [x] Problem A  

- [x] Problem B  

- [x] Problem C  

- [x] Problem D  
Solution: The key observation is that if the words are sorted then i < i + 1, this is true only for a [c,c'] shifts.  
This is easy to compute, after having this information we just have to check the intersection of these intervals which can be done in O(n) with prefix sums, adding 1 when interval starts and substracting 1 when interval ends. Then we check if for some i, pref[i] == n-1.  
Complexity: O(n)

- [ ] Problem E  

- [ ] Problem F  
