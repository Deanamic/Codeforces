Atcoder Grand Contest 018

[Contest link](http://agc018.contest.atcoder.jp/)  
[Editorial link](http://codeforces.com/blog/entry/48582)  

- [x] Problem A  
So first we observe that if d|A and d|B, d|(A-B), then we can see that the smallest value we can obtain is the gcd of all the integers. Hence the problem is solvable iff the exists a<sub>i</sub> such that gcd|K - a<sub>i</sub>.  

- [x] Problem B  
At each step we know that the answer is at most k, and the only way to improve it is by taking away the event with k participants. We can do it greedily and solve the problem.  

- [x] Problem C  
Let's sort the solution by A - B, then the solution will be ..A..AC..CA..A... | C..CB..BC..C.., we can look for the divisor.  

- [x] Problem D  
Solution: get the centroid and make a route which changes subtree each time.

- [ ] Problem E  

- [ ] Problem F  
