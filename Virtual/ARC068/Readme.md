Contest ARC068 Atcoder Regular Contest  
[Contest Link](http://arc068.contest.atcoder.jp)  
[Editorial Link](https://atcoder.jp/img/arc068/editorial.pdf)  

- [x] Problem C  

- [x] Problem D  

- [x] Problem E  
There are M+1 stations, numbered from 0 to M. You are at station 0 and there are M trains, the i-th train stops exery i stations.  There are also N shops with the i-th shop being open in [l<sub>i</sub>, r<sub>i</sub>], For each train you can ride, how many diferent shops can you visit?  
Let's consider a train which stops every d stations, and lets consider a shop s, there are 2 cases. the interval where the shop opens is larger or equal to d, or it is smalles. In the first case you will be able to visit that shop no matter what, in the latter case you will be able to visit the shop at most once.   
Now we can come up with a solution, we wiil calculate the value for all the trains but we only add the shop to the data structure iff it's interval is shorter than d, we can use a Fenwick tree or a SegmentTree to do this.  
Complexity. O(NlogN + MlogM*logN)  

- [ ] Problem F
