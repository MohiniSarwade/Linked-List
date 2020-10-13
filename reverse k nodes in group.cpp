struct node *reverse (struct node *head, int k)
{ 
    // Complete this method
    node *cur=head;
    node *prv=NULL,*next=NULL;
    int count=0;
    while(cur!=NULL && count<k)
    {
        next=cur->next;
        cur->next=prv;
        prv=cur;
        cur=next;
        count++;
    }
    if(next!=NULL)
        head->next=reverse(next,k);
    
    return prv;
}
