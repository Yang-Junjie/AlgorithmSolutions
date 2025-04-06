## Codeforces 1015 A
[1015A Max and Mod](https://codeforces.com/contest/2084/problem/A)
这是一题构造题。需要我们构造一个排列p满足$\max(p _ {i - 1}, p _ i) \bmod i=i-1$

 - 直接观察样例猜想偶数排列一定不行
 - 对于奇数排列5需要满足以下规律
![](/imgs/2025-04-06/rIwAybjR6awIzbPm.jpeg)
 - 对于偶数排列不满足以上规律偶数mod2必然不等于1

