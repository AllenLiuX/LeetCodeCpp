Tags: stack, 字符串, 中等
根据逆波兰表示法，求表达式的值。

有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

说明：

整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
示例 1：

输入: ["2", "1", "+", "3", "*"]
输出: 9
解释: ((2 + 1) * 3) = 9
示例 2：

输入: ["4", "13", "5", "/", "+"]
输出: 6
解释: (4 + (13 / 5)) = 6
示例 3：

输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
输出: 22
解释: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/evaluate-reverse-polish-notation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

class Solution {
public:
    bool dig(string s){
        if(s!="+" && s!="-" && s!="/"&& s!="*")
            return true;
        return false;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string ss : tokens){
            if(dig(ss))
                s.push(stoi(ss));
            else{
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                char c = ss[0];
                switch(c){
                    case '+':
                        s.push(a+b);
                        break;
                    case '-':
                        s.push(b-a);
                        break;
                    case '*':
                        s.push(a*b);
                        break;
                    case '/':
                        s.push(b/a);
                        break;
                }
            }
        }
        return s.top();
    }
};