class Solution {
  public:
    string convert(string s, int numRows)
    {
        // second
        if (numRows == 1)
            return s;
        int   length = s.size();
        int   circle = numRows * 2 - 2;
        char* a      = new char[length + 1];
        int   count  = 0;
        int   t      = 0;
        while (t < length) {
            a[count++] = s[t];
            t += circle;
        }
        int step1, step2;
        for (int midRow = 1; midRow <= numRows - 2; midRow++) {
            t     = midRow;
            step2 = midRow + midRow;
            step1 = circle - step2;
            while (t < length) {
                a[count++] = s[t];
                t += step1;
                if (t >= length)
                    break;
                a[count++] = s[t];
                t += step2;
            }
        }
        t = numRows - 1;
        while (t < length) {
            a[count++] = s[t];
            t += circle;
        }
        a[count] = '\0';
        return a;

        // first
        // if (numRows == 1)
        //     return s;
        // int   length = s.size();
        // int   circle = numRows * 2 - 2;
        // char* a      = new char[length + 1];
        // int   count  = 0;
        // for (int i = 0; i < (length - 1) / circle + 1; i++) {
        //     a[count++] = s[i * circle];
        // }
        // for (int midRow = 1; midRow <= numRows - 2; midRow++) {
        //     for (int i = 0; i < length / circle; i++) {
        //         a[count++] = s[i * circle + midRow];
        //         a[count++] = s[(i + 1) * circle - midRow];
        //     }
        //     if ((length / circle) * circle + midRow >= length)
        //         continue;
        //     a[count++] = s[(length / circle) * circle + midRow];
        //     if ((length / circle + 1) * circle - midRow >= length)
        //         continue;
        //     a[count++] = s[(length / circle + 1) * circle - midRow];
        // }
        // for (int i = 0; i < (length + numRows - 2) / circle; i++) {
        //     a[count++] = s[i * circle + numRows - 1];
        // }
        // a[count] = '\0';
        // return a;
    }
};
// @lc code=end
/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

/*
0:02 开始
0:28 写
0:39 调试
1:01 bug1
1:14 提交问题1
1:18 bug2
1:24 提交成功
1:37 第二版提交问题1
2:01 bug3
2:02 第二版提交成功

开始
感觉题略简单

策略
1. 一行一行输出
2. 分为首行 末行 中间行
3. 中间行按行号来计算，对称
4. 首循环：for (int i=0;i<(length-1)/circle+1;i++)
5. 引入count
a[count++]=s[i*circle];
6. 中间层有numRows-2层，从1开始
for(int midRow=1;midRow<=numRows-2;midRow++)
7. 中间层 for(int i=0;i<length/circle;i++)
将余下的单独if讨论，在midRows的for中
i*circle+midRow (i+1)*circle-midRow
8. 结尾层 (length+1)/circle

结构
1. length circle 初始a
2. 三个for 输出

c++string申请：必须填入两个参数
string a(length, NULL);
以length为长度申请就好，会自动在后面加'\0'

bug1 string的申请方式，还是用最原始的来吧
string a(length, NULL);
char* a      = new char[length + 1];

提交问题1
'A' 2 stack overflow

bug2 结尾部分的公式推导
原来以为有(length + 1) / circle次
计算的时候以numRows=3为基准，得到bais为+1
但numRows=2和4时，结果是0和2，所以bais是numRows-2

提交成功
1157/1157 cases passed (12 ms)
Your runtime beats 75.11 % of cpp submissions
Your memory usage beats 96.62 % of cpp submissions (8 MB)

第二版提交问题1
"PAYPALISHIRING"
3
"PAHNAYIR"
"PAHNAPLSIIGYIR"
但是在https://www.dooccn.com/cpp/ 问题无法复现orz

bug3
step1 = circle - step1;
step1 = circle - step2;

第二版提交成功
1157/1157 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 96.69 % of cpp submissions (8 MB)
*/