---
layout: post
title:  "双指针"
date:   2015-10-04 16:47:00
categories: 双指针
---

#### 前言

用到双指针的题一般来说是有2个指针，一个是当前指针，一个是当前位置前边的一个指针；
2个指针可以构成一个“窗口”，围绕窗口可以进行一些操作；

- 比如下边的1、2、4、5题，窗口左边是选好的结果，窗口右边是待选得结果，窗口中间是没什么用的元素，可以被覆盖的；
- 7、8、9题，窗口中间是有可能成为结果的元素，窗口右边是待选，左边是没有可能成为结果的；
- 10、11、12则是，先固定最左边的元素，剩下的2个指针组成窗口，窗口不断缩小，减少搜索范围。当然我们这么做的前提是数组排好序。
- 13 没有想明白。

#### 数据结构为数组：

- <https://leetcode.com/problems/move-zeroes/>
- <https://leetcode.com/problems/remove-element/>
- <https://leetcode.com/problems/valid-palindrome/>
- <https://leetcode.com/problems/remove-duplicates-from-sorted-array/>
- <https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/>
- <https://leetcode.com/problems/merge-sorted-array/>
- <https://leetcode.com/problems/longest-substring-without-repeating-characters/>
- <https://leetcode.com/problems/substring-with-concatenation-of-all-words/> not easy to understand
- <https://leetcode.com/problems/minimum-size-subarray-sum/> not easy to understand
- <https://leetcode.com/problems/3sum/> not easy to think.
- <https://leetcode.com/problems/3sum-closest/>
- <https://leetcode.com/problems/4sum/>
- <https://leetcode.com/problems/container-with-most-water/> not understand

#### 链表：

- <https://leetcode.com/problems/remove-nth-node-from-end-of-list/>
- <https://leetcode.com/problems/palindrome-linked-list/>



