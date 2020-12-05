#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int kthToLast(ListNode* head, int k) {
    ListNode* p = head;
    int n = 1;
    while(p->next){
        n++; 
        p = p->next;
    }
    ListNode* q = head;
    for(int i = 0;i < (n-k);i++)
        q = q->next;
    return q->val;
}

int kthToLast1(struct ListNode* head, int k){// 题解：快慢指针问题，设置两个指针
    struct ListNode* first = head;
    struct ListNode* last = head;
    for(int i = 1; i < k ;i++)
        first = first->next;
    while(first->next)
    {
        first = first->next;
        last=last->next;
    }
    return last->val;
}

int main()
{

}