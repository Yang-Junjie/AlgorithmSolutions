# CF2094D Tung Tung Sahur

## 题目描述

You have two drums in front of you: a left drum and a right drum. A hit on the left can be recorded as "L", and a hit on the right as "R".

The strange forces that rule this world are fickle: sometimes, a blow sounds once, and sometimes it sounds twice. Therefore, a hit on the left drum could have sounded as either "L" or "LL", and a hit on the right drum could have sounded as either "R" or "RR".

The sequence of hits made is recorded in the string $$$p$$$, and the sounds heard are in the string $$$s$$$. Given $$$p$$$ and $$$s$$$, determine whether it is true that the string $$$s$$$ could have been the result of the hits from the string $$$p$$$.

For example, if $$$p=$$$"LR", then the result of the hits could be any of the strings "LR", "LRR", "LLR", and "LLRR", but the strings "LLLR" or "LRL" cannot.

## 输入格式

The first line contains an integer $$$t$$$ ($$$1 \\leq t \\leq 10^4$$$) – the number of independent test cases.

The first line of each test case contains the string $$$p$$$ ($$$1 \\le |p| \\le 2 \\cdot 10^5$$$) consisting only of the characters "R" and "L", where $$$|p|$$$ denotes the length of the string $$$p$$$.

The second line of each test case contains the string $$$s$$$ ($$$1 \\le |p| \\le |s| \\le 2 \\cdot 10^5$$$) consisting only of the characters "R" and "L".

It is guaranteed that the sum of $$$|s|$$$ does not exceed $$$2\\cdot 10^5$$$ across all test cases.

## 输出格式

For each set of input data, output "YES" if $$$s$$$ can be the heard sound, and "NO" otherwise. You may output in any case.

## 输入输出样例 #1

### 输入 #1

```
5
R
RR
LRLR
LRLR
LR
LLLR
LLLLLRL
LLLLRRLL
LLRLRLRRL
LLLRLRRLLRRRL
```

### 输出 #1

```
YES
YES
NO
NO
YES
```
大致题意是给你两个字符串p,s，p字符串是由LR组成的，s是由p生成的，生成规则如下：
1. p中的每个L或R能选择性的在原地复制一个
例如p:LLRL
那么s可以是：LLLLRRLL、LLRL，LLLRRLL，LLRRLL，LLRRL等其中一个

思路：
1. 可以发现按照生成规则我们可以知道s中每一个连续的部分，如连续的L，连续的R，一定大于p中对应连续的L或RR
如s为LLLLRRL p为LLRL，s中LLLL对应LL且长度大于等于p的长度，其他同理，
2. 再可以发现2*p的对应位置一定大于等于s中对应位置的长度，因为最大生成这么多

代码思路：
使用两个指针l,r分别指向p和s，从头向后遍历字符串，找到两个字符串对应位置的长度，然后判断思路中的条件，如果不满足直接跳出输出，如果遍历完还满足则输出YES

总结:
代码上的：记住指针遍历思想
比赛上的：其实比赛上已经想到条件情况了，但是当时没想好要用指针遍历，当时想到的是前面一个字符不等于现在这个字符的遍历方式
指针遍历一般使用while
冷静冷静冷静！！！！！！！！！！！！！！！！！！！！！
