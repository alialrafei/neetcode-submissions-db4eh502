class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;
       
        ListNode* tmp = head;
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* start = head;
        int n = 0;
        while(start && start->next){
            n++;
            start = start->next;
        }
        int tmpidx = 1;
        first->next = NULL;
        while(tmpidx<=n){
            if(second && second->next){
                tmp = second->next;
            }
            second->next = first;
            first = second;
            if(tmp && tmpidx+1<= n)
                second = tmp;
            tmpidx++;
        }
        return second;
    }
};

