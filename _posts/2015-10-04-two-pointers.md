---
layout: post
title:  双指针
date:   2015-10-04 16:47:00
categories: summary
---

#### 前言

用到双指针的题一般来说是有2个指针，一个是当前指针，一个是当前位置前边的一个指针；
2个指针可以构成一个“窗口”，围绕窗口可以进行一些操作；

- 比如下边的1、2、4、5题，窗口左边是选好的结果，窗口右边是待选得结果，窗口中间是没什么用的元素，可以被覆盖的；
- 7、8、9题，窗口中间是有可能成为结果的元素，窗口右边是待选，左边是没有可能成为结果的；
- 10、11、12则是，先固定最左边的元素，剩下的2个指针组成窗口，窗口不断缩小，减少搜索范围。当然我们这么做的前提是数组排好序，能比暴力法减少一个n的量级，也就是从O(n^3)减小到了O(n^2)。
- 13 没有想明白。

#### 数据结构为数组：

1. <https://leetcode.com/problems/move-zeroes/>
2. <https://leetcode.com/problems/remove-element/>
3. <https://leetcode.com/problems/valid-palindrome/>
4. <https://leetcode.com/problems/remove-duplicates-from-sorted-array/>
5. <https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/>
6. <https://leetcode.com/problems/merge-sorted-array/>
7. <https://leetcode.com/problems/longest-substring-without-repeating-characters/>
	+ 主要思想是，尽量利用之前计算过的信息，比如将指针移动到没有重复的地方。
8. <https://leetcode.com/problems/substring-with-concatenation-of-all-words/> not easy to understand
9. <https://leetcode.com/problems/minimum-size-subarray-sum/> 
10. <https://leetcode.com/problems/3sum/> not easy to think.
11. <https://leetcode.com/problems/3sum-closest/>
12. <https://leetcode.com/problems/4sum/>
13. <https://leetcode.com/problems/container-with-most-water/> not understand
14. <https://leetcode.com/problems/sort-colors/>
 和[Dutch National Flag](http://www.csse.monash.edu.au/~lloyd/tildeAlgDS/Sort/Flag/)一样。左指针左边是0，右指针右边是2，左指针和当前下边index中间是1，其余的部分是待遍历元素。

#### 链表：

- <https://leetcode.com/problems/remove-nth-node-from-end-of-list/>
- <https://leetcode.com/problems/palindrome-linked-list/>

#### 代码
<https://github.com/fanyingming/leetcode/tree/master/two%20pointers>


