CONTEST Codeforces 675 Round 353 Div 2

[Contest link](http://codeforces.com/contest/675)  
[Editorial link](http://codeforces.com/blog/entry/44902)

- [x] Problem A  

- [x] Problem B  

- [x] Problem C  
So we are given N banks in a circle, a bank can transfer money to a neighbouring bank independently of the current balance. We are guaranteed that the sum of values is equal to 0. Which is the minimum possible number of operations to make all the banks have 0 money.  
So lets have a first observation:  
This can always be achieved in n-1 steps, at each step we can make a bank have 0 money, and the last one will have 0.  
We can also see that if a transfer doesnt occur between i and i+1, there is no money sent from j to k, j < i and k > i. Then we will do n-2 operations. Actually, we will do n-k operations where k is the number of segments of transfers.  
It is easy to see that to have the maximum number of such segments we just have to find the maximum number of 0-sum segments.  
This can easily be done with a map.
Complexity: O(nlogn)  

- [x] Problem D  
This problems asks as to make N insertions to a BST.  
This is a quite straight forward, we will look for the largest value lesser than a<sub>i</sub> and the least value larger than a<sub>i</sub>.
We are sure we can be the left child of this node, except the case where it already has a left child, then simply we will be the right child of our lowerbound, which is guaranteed to be available.
Complexity: O(nlogn)  

- [x] Problem E  
We are given N train stasions, from the i-th one you can reach to [i+1,a<sub>i</sub>] with one ticket. Let p<sub>i,j<sub> be the minimum number of tickets we need to go from station i to station j. We are asked to compute the sum over all i,j i < j.
Lets consider train station i. we can go to [i+1,a<sub>i</sub>], with one ticket. If we want to reach (a<sub>i</sub>, n] we will have to commute to a station in our reachable interval. To find the optimal station to go, we have to observe that a station is better than another iff the range it can reach is larger, hence we are also guaranteed that the train station t<sub>op</sub> to do the commute can reach [t<sub>op</sub> + 1,a<sub>i</sub>] in one step.  
Given that, the cost to visit the rest of the stations passing through the j-th station is:  
(n - a<sub>i</sub>) - (a<sub>i</sub> - j) + (a<sub>i</sub> - i)+ dp[j].
where dp[j] it the sum of p<sub>j,k<sub> for all k.  
To find the optimal j we can simply use a segment tree and search for the one with largest range.  
Complexity: O(nlogn)  
