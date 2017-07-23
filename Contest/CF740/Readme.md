Codeforces 740 Round 381 Div 2

[Contest link](http://codeforces.com/contest/740)  
[Editorial link](http://codeforces.com/blog/entry/48582)  

- [x] Problem A  

- [x] Problem B  

- [x] Problem C  
We can first see that the answer is at most the minimum length of a segment + 1. We can see that if the array values are:  
0, 1, 2, 3, .., ans - 1, 0 ,.. no matter what segment of length ans we pick we will always find that the mex is ans.  

- [x] Problem D  
So playing around the inequality we can see that v controls u iff depth[v] >= depth[u] - a[u].  
Also as the depth[v] is a monotonous function which only grows as we go down the tree there exist one node such that all its child and itself fulfil the inequality. We can binary lift for this answer and obtain values using prefix sums.  
Complexity: O(nlogn)

- [ ] Problem E  
