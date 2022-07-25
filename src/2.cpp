

 struct ListNode {
       int val;
       ListNode *next;
       ListNode() : val(0), next(nullptr) {}
       ListNode(int x) : val(x), next(nullptr) {}
       ListNode(int x, ListNode *next) : val(x), next(next) {}
   };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1, *ptr2 = l2;
        int r = 0, sum = 0, val1, val2;
        ListNode* s = new ListNode(); ListNode* h = s;
        bool beg = 1;
        while(ptr1 != nullptr || ptr2 != nullptr){
            if(beg){
                sum = ptr1->val + ptr2->val;
                s->val = sum % 10 ; 
                beg = 0;
                if(sum>9){r = sum / 10;}}
            else{
                if(ptr1 != nullptr){ptr1 = ptr1->next;}
                if(ptr2 != nullptr){ptr2 = ptr2->next;}
                if(ptr1 == nullptr && ptr2 == nullptr && r == 0){break;}
                if(ptr1 != nullptr){val1 = ptr1->val;} else{val1 = 0;}
                if(ptr2 != nullptr){val2 = ptr2->val;} else{val2 = 0;}
                sum = val1 + val2;
                s->next = new ListNode((sum + r)%10);
                s = s->next;
                if(sum + r>9){r = (sum + r) / 10;} else{r = 0;}
            }
        }
        return h;
    }
};