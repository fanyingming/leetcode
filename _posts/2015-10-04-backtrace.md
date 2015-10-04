---
layout: post
title:  "回朔"
date:   2015-10-04
categories: backtrace
---

#### 前言

利用《算法设计手册》backtrace一章中提到的固定模式来写代码，当然其中一些部分可以简写；
一些题目可能还需要大量剪枝，以加速运行；

- 一种剪枝方法是看能否使用哈希表，只对需要的元素进行回朔；
- 一种剪枝是及时判断，发现后边的元素一定不可能是备选，则可以跳过后边的备选。

#### 排列
- <https://leetcode.com/problems/permutations/>
- <https://leetcode.com/problems/permutations-ii/>
- <https://leetcode.com/problems/permutation-sequence/>
- <https://leetcode.com/problems/next-permutation/>

#### 组合：
- <https://leetcode.com/problems/subsets/>
- <https://leetcode.com/problems/subsets-ii/> 考虑重复
- <https://leetcode.com/problems/combinations/>
- <https://leetcode.com/problems/combination-sum/>
- <https://leetcode.com/problems/combination-sum-ii/>
- <https://leetcode.com/problems/combination-sum-iii/>
- <https://leetcode.com/problems/letter-combinations-of-a-phone-number/>

#### 应用
- <https://leetcode.com/problems/n-queens/>
- <https://leetcode.com/problems/n-queens-ii/>
- <https://leetcode.com/problems/generate-parentheses/>
- <https://leetcode.com/problems/gray-code/>
- <https://leetcode.com/problems/restore-ip-addresses/>
- <https://leetcode.com/problems/word-search/>
- <https://leetcode.com/problems/palindrome-partitioning/>
- <https://leetcode.com/problems/sudoku-solver/>
- <https://leetcode.com/problems/add-and-search-word-data-structure-design/>
- <https://leetcode.com/problems/regular-expression-matching/>

#### 代码
<https://github.com/fanyingming/leetcode/tree/master/backtrace>


