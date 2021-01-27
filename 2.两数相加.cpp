class Solution {
  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        // third draft
        ListNode* head = l1;
        int       sum  = 0;
        while (l1) {
            if (l2) {
                sum += l2->val;
            }
            sum += l1->val;
            l1->val = sum % 10;
            sum /= 10;
            if (!l1->next) {
                if (l2 && l2->next) {
                    l1->next = l2->next;
                    l1       = l2->next;
                    l2       = NULL;
                    continue;
                }
                if (sum) {
                    ListNode* addi = new ListNode(1);
                    l1->next       = addi;
                }
                break;
            }
            else if (l2) {
                l2 = l2->next;
            }
            l1 = l1->next;
        }
        return head;

        // second draft
        // ListNode* head = l1;
        // int       sum  = 0;
        // while (l1 != NULL) {
        //     if (l2 != NULL) {
        //         sum += l2->val;
        //     }
        //     sum += l1->val;
        //     l1->val = sum % 10;
        //     sum /= 10;
        //     if (l1->next == NULL) {
        //         if (l2 != NULL && l2->next != NULL) {
        //             l1->next = l2->next;
        //             l1       = l2->next;
        //             l2       = NULL;
        //             continue;
        //         }
        //         if (sum) {
        //             ListNode* addi = new ListNode(1);
        //             l1->next       = addi;
        //         }
        //         break;
        //     }
        //     else if (l2 != NULL) {
        //         l2 = l2->next;
        //     }
        //     l1 = l1->next;
        // }
        // return head;

        // first draft
        // ListNode* an   = l1;
        // ListNode* bn   = l2;
        // ListNode* ap   = NULL;
        // ListNode* bp   = NULL;
        // bool      plus = false;
        // while (an != NULL || bn != NULL) {
        //     if (an == NULL) {
        //         an       = bn;
        //         ap->next = an;
        //         bp->next = NULL;
        //         bn       = NULL;
        //     }
        //     if (bn != NULL) {
        //         an->val += bn->val;
        //     }
        //     if (plus) {
        //         an->val += 1;
        //         plus = false;
        //     }
        //     if (an->val > 9) {
        //         an->val -= 10;
        //         plus = true;
        //     }
        //     if (bn == NULL && plus == false) {
        //         break;
        //     }
        //     ap = an;
        //     an = an->next;
        //     if (bn != NULL) {
        //         bp = bn;
        //         bn = bn->next;
        //     }
        // }
        // if (plus) {
        //     ListNode* addi = new ListNode(1);
        //     ap->next       = addi;
        // }
        // return l1;

        // others' solution
        // ListNode* head = l1;
        // if (!l1)
        //     return l2;
        // if (!l2)
        //     return l1;
        // int sum = 0;
        // while (l1 || l2 || sum != 0) {
        //     if (l2) {
        //         sum += l2->val;
        //         l2 = l2->next;
        //     }
        //     if (l1) {
        //         sum += l1->val;
        //         l1->val = sum % 10;
        //         sum     = sum / 10;
        //         if (!(l1->next) && l2) {
        //             l1->next = l2;
        //             l2       = NULL;
        //         }  // l2链表结束后，l2接在l1后面。
        //         if (!(l1->next) && sum != 0) {
        //             l1->next = new ListNode(sum);
        //             break;
        //         }  //最后存在一次进位，开辟一个节点。
        //         l1 = l1->next;
        //     }
        // }
        // return head;
    }
};
// @lc code=end
/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 * /





最后多一个要加的逻辑
试探着加
if(p>9&&p->next==NULL){
    ListNode last=new ListNode(1);
    p=ListNode(p->val,last);
}

在原来的链表上合并
加的情况
1. 还有链表可以加
2. A还有，B没有了，还有进位：加，看是否还有进位
3. A还有，B没有了，没有进位：break
4. A没有了，B还有：把b移到a后面

使用an,bn,ap,bp似乎会顺一点
ap=an;
bp=bn;
an=an->next;
bn=bn->next;
当然要判断是否可以获得next，用an/bn判断

则最后多一个要加的逻辑
在while后加
while条件：while(an!=NULL&&bn!=NULL)

进位：bool plus

把b移到a后面
ab指针修改之后，ab四个变量也需要修改
an=bn;
ap->next=an;
bp->next=NULL;
bn=NULL;
作为if判断，判断先后
1. 先移动
2. b有就加，没有不变
3. 有进位加，没有不变
4. plus没有就break
5. 下一格：bn没有就不往前走

一格情况下，ap=bp=null似乎不影响。

14:45 开始coding
14:53 结束coding
15:03 bug1
while (an != NULL && bn != NULL)
while (an != NULL || bn != NULL)
15:04 first draft pass
1568/1568 cases passed (52 ms)
Your runtime beats 52.21 % of cpp submissions
Your memory usage beats 99.31 % of cpp submissions (68.9 MB)

15:27 写改进点
15:32 改
15:55 结束改
16:04 bug2
if (l2->next != NULL) {
if (l2!=NULL && l2->next != NULL) {
16:08 bug3
原来在判断l1l2翻转和有多一个节点之前先l1
next了，导致多一个节点找不到挂载的地方。现在放在最后加
16:22 bug4
l1 = l2->next;
l1->next=l2->next;l1 = l2->next;
16:25 second draft pass
1568/1568 cases passed (48 ms)
Your runtime beats 65.62 % of cpp submissions
Your memory usage beats 98.93 % of cpp submissions (69 MB)

16:41 third draft pass
1568/1568 cases passed (28 ms)
Your runtime beats 98.89 % of cpp submissions
Your memory usage beats 99.17 % of cpp submissions (69 MB)
做的事情就是将所有的A==null改成!A了。可能因为!A看的是zero
flag，而A==NULL，就是比较32位的A和32个0之间的关系

other1:
https://leetcode-cn.com/problems/add-two-numbers/solution/zhi-jie-zai-lian-biao-shang-cao-zuo-zui-duo-kai-pi/
1568/1568 cases passed (28 ms)
Your runtime beats 98.89 % of cpp submissions
Your memory usage beats 99.83 % of cpp submissions (68.8 MB)

第二稿可能改进点：
保留head=l1;不新建an等
不用plus，结果存在sum里，既做余数也做进位判断
如何解决最后一个节点传输问题：直接在跳出while前判断

*/