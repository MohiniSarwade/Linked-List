Node *pushFront(Node* head, int x)
{
    Node *new_node=new Node(x);
    if(head!=NULL)
    {
        new_node->next=head;
    }
    return new_node;
}
void Addremain(Node* first,Node *cur,int &carry,Node **res)
{
    if(first!=cur)
    {
        Node *new_node=new Node(0);
        Addremain(first->next,cur,carry,res);
        int sum=first->data+carry;
        carry=sum/10;
        int x=sum%10;
        new_node->data=x;
        new_node->next=*res;
        *res=new_node;
    }
    
}

Node* AddSame(Node*first,Node *second,int &carry)
{
    if(first==NULL)
        return NULL;
    Node *new_node=new Node(0);
    new_node->next=AddSame(first->next,second->next,carry);
    int sum=first->data+second->data+carry;
    carry=sum/10;
    int x=sum%10;
    new_node->data=x;
    return new_node;
}

int getsize(struct Node *head)
{
    int count=0;
    while(head!=NULL)
    {
        head=head->next;
        count++;
    }
    return count;
}
void swapNode(Node **first, Node ** second)
{
    Node *t=*first;
    *first=*second;
    *second=t;
}

struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    // code here
    int s1=getsize(first);
    int s2=getsize(second);
    int carry=0;
    Node *res=NULL;
    if(s1==s2)
        res=AddSame(first,second,carry);
    else
    {
        if(s1<s2)
            swapNode(&first,&second);
        int diff=abs(s1-s2);
        Node *cur=first;
        for(cur=first;diff--;cur=cur->next);
        res=AddSame(cur,second,carry);
        Addremain(first,cur,carry,&res);
       
    }
    
   
    if(carry)
        return pushFront(res,carry);
    return res;
}
