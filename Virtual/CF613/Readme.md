07/17 [CF 613 round 339 Div1](http://codeforces.com/contest/613)

- [x] Problem A  
The problem reduces to the following:  
Given the vertex of a polygon in clockwise order find the furthest and closest point.  
The furthest point must be a vertex whereas the nearest point can lie on a segment.  
Still it can easily be found by a ternary search or simply by formulae.  
Complexity O(nlogn) or O(n).

- [x] Problem B  
We are given an array of N <= 1e5 numbers, a<sub>i</sub> <= A. Now we can do Q operations of augmenting each point in the array by 1.  
We will say the value of the array is |a<sub>i</sub> = A| * c<sub>f</sub> + the minimum * c<sub>m</sub>.  
Given N, A, Q, c<sub>f</sub>, c<sub>m</sub>, what is the maximum value of the array.  
We can clearly see that all our operations will be used to make more numbers equal to A, or make the maximum of the array higher.  
If we want to raise numbers to the maximum it's obvious to use the greedy strategy of adding to the upper part, now if we have Q' operations left
we want to find the maximum possible minimum.  
Lets first sort the array an iterate over the number of values to max out, for each value we will have a maximum achievable minimum, as this value is non-increasing we can simply
use a second pointer to update the minimum.  
Complexity O(nlogn) for the sort.

- [ ] Problem C  

- [ ] Problem D  

- [ ] Problem E  
