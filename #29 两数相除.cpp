给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

返回被除数 dividend 除以除数 divisor 得到的商。

示例 1:

输入: dividend = 10, divisor = 3
输出: 3
示例 2:

输入: dividend = 7, divisor = -3
输出: -2
说明:

被除数和除数均为 32 位有符号整数。
除数不为 0。
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。
 
---

#define LIMIT 0x80000000

class Solution {
public:
    int divide(int dividend, int divisor) {
            
	if (dividend == 0) {
		return 0;
	}
	if (dividend == INT_MIN && divisor == -1) {
		return INT_MAX;
	}
	bool negative;
	negative = (dividend ^ divisor) < 0;//用异或来计算是否符号相异
	unsigned int t = dividend == INT_MIN ? LIMIT : abs(dividend);
	unsigned int d = divisor == INT_MIN ? LIMIT : abs(divisor);
	unsigned int result = 0;
	for (int i = 31; i >= 0; i--) {
		if ((t >> i) >= d) {//找出足够大的数2^n*divisor
			result += ((unsigned int)1) << i;//将结果加上2^n
			t -= d << i;//将被除数减去2^n*divisor
		}
	}
	if (result == LIMIT) {//特殊数不能将unsigned int转为int
		return INT_MIN;
	}
	else {
		return negative ? -(int)result : (int)result;//符号相异取反
	}
    }
};