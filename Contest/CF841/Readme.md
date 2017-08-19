Codeforces 839 Round 428 Div 2  
[Contest Link](http://codeforces.com/contest/839)  
[Editorial Link](http://codeforces.com/blog/entry/53815)  

- [x] Problem A  

- [x] Problem B  

- [x] Problem C  

- [x] Problem D  

- [x] Problem E  
Let's define an equivalent class where x and y are equivalent <=> x*y is a perfect square, it is reflexive, transitive and symmetric.  
Now lets group elements into c classes. Let f[i] be the number of elements in the i-th class of equivalence and dp[i][j] be the number of ways to achive j adjacent elements from the same class of equivalence using the first i groups. The answer will be dp[c-1][0].  
Let's observe how we can update our dp.
  - we will insert f[i] elements into K spots, K will range from 1 to the minimum of f[i] and the number of existing elements + 1, let's call this value X.  
  - From this K spots, L will be between 2 equivalent elemens, L will range from 0 to the minimum of j and k.  
  - We will choose how many objects we will put in each of the K spots (at least one)
  - As order matters, we will choose all permutations of the i-th group.  
  
The number of ways to do this is: (j choose L) * (X + 1 - j choose K - L) * (f[i] - 1 choose K - 1) * f[i]!  
And after adding this we will add the value to dp[i+1][j - L + f[i] - K]  
  - If we put all elements together, we create f[i]-1 adjacent equivalet elements, for each extra spot we create one less.  
  - Every time we choose a spot between 2 adjacent equivalent elements we have one less.  
