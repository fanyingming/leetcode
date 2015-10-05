---
layout: post
title:  "bit manipulation"
date:   2015-10-04 16:50:00
categories: 题型总结
---

#### 利用int的二进制中的bit。

利用一个特性，如果所有数都出现n次，只有一个数出现1次，怎么求这1个数。
我能够理解的做法是，开辟int bits[32]，i:0-31，bits[i]累加每个数的二进制，最后结果对n取模，然后留下的32位组成的数就是那个单独的数。

- <https://leetcode.com/problems/single-number/>
- <http://oj.leetcode.com/problems/single-number-ii/>
- <https://leetcode.com/problems/number-of-1-bits/>
- <https://leetcode.com/problems/missing-number/>
- <https://leetcode.com/problems/power-of-two/>
- <https://leetcode.com/problems/reverse-bits/>

#### 其他
- <http://oj.leetcode.com/problems/divide-two-integers/>
- <https://leetcode.com/problems/majority-element/>

#### 代码
<https://github.com/fanyingming/leetcode/tree/master/bit%20manipulate>



