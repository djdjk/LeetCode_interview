#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int x) {//超时
    ListNode* p = head;
    ListNode* headl; ListNode* headr; ListNode* l; ListNode* r;
    int cnt1 = 0, cnt2 = 0;
    while(p)
    {
        if(p->val < x){
            cnt1 ++;
            if(cnt1 == 1){
                headl = p;
                l = p; 
            } 
            else
                l->next = p; l = l->next; 
        }

        if(!(p->val < x)){
            cnt2 ++;
            if(cnt2 == 1){
                headr = p;
                r = p;
            }
            else
                r->next = p; r = r->next;
        }
        p = p->next;
    }
    l->next = headr;
    return headl;

}

ListNode* partition(ListNode* head, int x) {//自己用双指针做的，复杂度比较高，但是通过了
    if(head == NULL) return head;
    ListNode* p = head;
    ListNode* q = head->next;
    int swap = 3;
    while(swap)
    {
        swap = 0; //Whether there is swap in a loop
        p = head;
        q = head->next;
        while(q)
        {
            if(p->val >= x && q->val < x){
                swap ++;
                int tem = p->val;
                p->val = q->val;
                q->val = tem;
            }
            p = p->next;
            q = q->next;
        }
    }
    return head;

}

ListNode* partition(ListNode* head, int x) {//题解
    ListNode* pre = head;
    ListNode* cur = head;
    while(cur){
        if(cur->val < x){
            int temp = pre->val;
            pre->val = cur->val;
            cur->val = temp;
            pre = pre->next;
        }
        cur = cur->next;
    }
    return head;
}