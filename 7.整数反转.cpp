
class Solution {
  public:
    int reverse(int x)
    {
        int ans = 0;
        int remains;
        while (x) {
            remains = x % 10;
            if (x > 0 &&
                (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && remains > 7)))
                return 0;
            if (x < 0 &&
                (ans < -INT_MAX / 10 || (ans == -INT_MAX / 10 && remains < -8)))
                return 0;
            ans = 10 * ans + remains;
            x /= 10;
        }
        return ans;
    }
};
// @lc code=end
/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

/*

10:01 开始
10:08 答案
10:15 写
10:17 调试
10:18 bug1
10:24 bug2
10:30 提交通过

开始
1. bool flag=false;
2. 翻转过符号变化，就返回0
3. 用long解决(好吧 不可以用)
4. 不会 不知道如何判断翻转情况

答案
1. 如果 rev == INTMAX/10，那么只要 pop>7就会溢出。
2. 先在每一步操作之前处理
3. 直接分成rev > INTMAX/10和rev == INTMAX/10两部分写

计算逻辑
            remains = x % 10;
            if (flag) {
                if (ans > INTMAX / 10 || (ans == INTMAX / 10 && remains > 7))
                    return 0;
            }
            else {
                if (ans > INTMAX / 10 || (ans == INTMAX / 10 && remains > 8))
                    return 0;
            }
            ans = 10 * ans + remains;
            x /= 10;
if (flag) ans=0-ans;

bug1：INT_MAX is right
bug2：x%10是带符号的，例子：
    int i=-321;
    while(i){
        cout<<i%10<<endl;
        i/=10;
    }
-1
-2
-3

提交通过
1032/1032 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 99.53 % of cpp submissions (5.6 MB)

*/
