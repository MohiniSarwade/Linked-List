class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *tmp=l1;
        ListNode *tmp1=l2,*res=NULL,*fp=NULL;
        int carry=0;
        while(tmp!=NULL || tmp1!=NULL)
        {   
            ListNode *p=new ListNode(0);
            int sum=((tmp)?tmp->val:0)+((tmp1)?tmp1->val:0)+carry;
            carry=sum/10;
            int x=sum%10;
            p->val=x;
            if(fp==NULL)
                fp=p;
            else
                res->next=p;
            res=p;
            if(tmp)
                tmp=tmp->next;
            if(tmp1)
                tmp1=tmp1->next;
            
        }
        
        if(carry>0)
        {
            ListNode *p=new ListNode(carry);
            res->next=p;
        }
        return fp;
    }
};
