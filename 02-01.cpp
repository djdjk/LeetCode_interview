#include<iostream>
#include<set>

using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeDuplicateNodes(ListNode* head) {
    ListNode* p = head;
    if(head == NULL) return head;
    else{
        set<int> s;
        s.insert(p->val);
        while(p->next){
            if( s.count(p->next->val) ){
                p->next = p->next->next;
            }   
            else{
                s.insert(p->next->val);
                p = p->next;
            } 
        }
    }
    return head;
}

ListNode* removeDuplicateNodes2(ListNode* head) {

}//双指针法，不需要额外的空间
int main()
{
   
}

