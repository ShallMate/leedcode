/*给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/

#include<iostream>
using namespace std;
#include<vector>

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int addnum = 0;
        if((l1->val+l2->val)>=10)
            addnum = 1;
        head = new ListNode((l1->val+l2->val)%10);
        ListNode * p1 = head;
        ListNode * p2 = l1;
        ListNode * p3 = l2;
        while(p2->next||p3->next||addnum){
            ListNode * e;
            if(p2->next&&p3->next){
                p2 = p2->next;
                p3 = p3->next;
                e = new ListNode((p2->val+p3->val+addnum)%10);
                if((p2->val+p3->val+addnum)>=10)
                    addnum =1;
                else
                    addnum =0;
            }
            else if(!p2->next&&p3->next){
                p3 = p3->next;
                e = new ListNode((p3->val+addnum)%10);
                if((p3->val+addnum)>=10)
                    addnum =1;
                else
                    addnum =0;
            }else if(!p3->next&&p2->next){
                p2 = p2->next;
                e = new ListNode((p2->val+addnum)%10);
                if((p2->val+addnum)>=10)
                    addnum =1;
                else
                    addnum =0;
            }else if(!p2->next&&!p3->next&&addnum==1){
                e = new ListNode(1);
                addnum = 0;
            }
            p1->next = e;
            p1 = p1->next;
        }
    p1->next = NULL;
    return head;
    }

    void CreateList(int * l,int length);
    void ShowList();
    ListNode* head;
};

void Solution::ShowList(){
    ListNode * p =head;
    while(p){
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;
}

void Solution::CreateList(int* l,int length){
    head = new ListNode(*l);
    ListNode * p = head;
    for(int i=1;i<length;i++){
        ListNode * e = new ListNode(l[i]);
        p->next = e;
        p = p->next;
    }
}
