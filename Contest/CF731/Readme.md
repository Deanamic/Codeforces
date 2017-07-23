CONTEST Codeforces 731 Round 370 Div 2

[Contest link](http://codeforces.com/contest/731)  
[Editorial link](http://codeforces.com/blog/entry/47840)  

- [x] Problem A  

- [x] Problem B  

- [x] Problem C  

- [x] Problem D  
Solution: The key observation is that if the words are sorted then i < i + 1, this is true only for a [c,c'] shifts.  
This is easy to compute, after having this information we just have to check the intersection of these intervals which can be done in O(n) with prefix sums, adding 1 when interval starts and substracting 1 when interval ends. Then we check if for some i, pref[i] == n-1.  
Complexity: O(n)

- [x] Problem E  
Solution: At any point in the array we have sum(0, i), a<sub>i+1</sub> .. a<sub>n</sub>. We can easily that the amount of stickers left doesn't depend on anything but the index, hence we can see the problem as a dp problem where dp[i] = max(sum(0, j) - dp[j]). This is a O(n<sup>2</sup>), easily optimized to O(n).

- [x] Problem F  
You can simply bruteforce the answer, remember that (n/1 + n/2 + ... + n/n) is nlog(n).
