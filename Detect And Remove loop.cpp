void removeLoop(Node* head)
{
    // code here
    // just remove the loop without losing any nodes
    if(head==NULL||head->next==NULL)
        return;
    Node *tmp=NULL;
    bool f=false;
    Node *slow=head,*fast=head;
    
    while(fast&& fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            break;
        }
       
    }
    if(slow==head)
    {
        while(slow->next!=head)
            slow=slow->next;
        slow->next=NULL;
    }
    if(slow==fast)
    {
        slow=head;
        while(slow->next!=fast->next)
        {
            fast=fast->next;
            slow=slow->next;
        }
        fast->next=NULL;
    }
}
