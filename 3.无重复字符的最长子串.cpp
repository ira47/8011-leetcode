class Solution {
  public:
    int lengthOfLongestSubstring(string s)
    {
        queue<char>  q;
        vector<bool> dict(256);
        int          count = 0;
        for (char& cn : s) {
            while (dict[cn]) {
                dict[q.front()] = false;
                q.pop();
            }
            dict[cn] = true;
            q.push(cn);
            if (q.size() > count) {
                count = q.size();
            }
        }
        return count;
    }
};
// @lc code=end
/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

/*

16:52 开始思路
17:04 开始coding
17:14 结束coding
17:15 finish
987/987 cases passed (4 ms)
Your runtime beats 98.32 % of cpp submissions
Your memory usage beats 74.1 % of cpp submissions (7.7 MB)
17:17 其实可以自制queue实现，因为queue长度无非256.用%256来确实信息存储的位置
甚至直接start_point来代表queue，因为queue的顺序和字符串的顺序是一致的，可以从字符串获得queue信息。size用end-start来表示


思路
1. 正查和反查
2. 一旦发现堵塞，就弹出，直到可以把新的这个放进去。
3. 还有符号，因此直接开256的bool数组做list
4. 每次加一个新的，就更新一下count


尝试：自己记录queueLength和用它的的区别

@TODO
1. queue pop是否返回结果->不
2. 什么能读queue->front()
3. vector初始化：括号
4. queue的长度->size()











*/