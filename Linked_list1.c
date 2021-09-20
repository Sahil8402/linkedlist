#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node* next;
};
struct node*head;
void ll_traversal();
void ll_insert_first();
void ll_insert_Atindex();
void ll_randominsert();
void ll_insertlast();
void ll_delete_first();
void ll_delete_atindex();
void ll_delete_atend();
void main(){
    int c;
    while(c!=9){
        printf("\nHere are the choice\n");
        printf("1:Display\n");
        printf("2:insert_first\n");
        printf("3:insert_At index\n");
        printf("4:By index adding\n");
        printf("5:insert_last\n");
        printf("6:delete_first\n");
        printf("7:delete_atindex\n");
        printf("8:delete_last\n");
        printf("Enter Choice:-");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            ll_traversal();
            break;
        
        case 2:
            ll_insert_first();
            break;
        case 3:
           ll_insert_Atindex();
           break;
        case 4:
           ll_randominsert();
           break;
        case 5:
           ll_insertlast();
           break;
        case 6:
           ll_delete_first();
           break;
        case 7:
           ll_delete_atindex();
           break;
        case 8:
           ll_delete_atend();
           break;
        }
    }


}

void ll_traversal(){
    struct node *ptr;
    ptr=head;
    if(ptr==NULL)
    {
        printf("\nNothing to traverse..\n");

    }
    else
    {
         while (ptr!=NULL)
         {
             printf("%d->",ptr->data);
             ptr=ptr->next;
         }
         
    }
    
}
void ll_insert_first(){
    struct node*ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("Can't Insert");
    
    }
    else{
         printf("Enter Value:-");
         scanf("%d",&ptr->data);
         ptr->next=head;
         head=ptr;
         printf("Node inserted Successfully");
    }
}
//this is inserting by value
void ll_insert_Atindex(){
    int value,key;
    printf("Enter number after which you want to add:-");
    scanf("%d",&key);
    struct node* newnode,*ptr,*p;
    newnode=(struct node* )malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("No node created");
    }
    printf("Enter Value to be inserted:-");
    scanf ("%d",&newnode->data);
    if(head== NULL)
    {
        printf("This is for adding at first");
        newnode->next=NULL;
        newnode=head;
    }
    else 
    {
        ptr=head;
        p=head;
        while(p->data!=key)
        {
            ptr=ptr->next;
            p=p->next;

        }
        newnode->next=p->next;
        p->next=newnode;
        printf("Node inserted successfully");
        
    }
}
//this in inserting by index
void ll_randominsert()  
{  
    int i,loc,item;   
    struct node *ptr, *temp;  
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {  
        printf("\nEnter element value");  
        scanf("%d",&item);  
        ptr->data = item;  
        printf("\nEnter the location after which you want to insert ");  
        scanf("\n%d",&loc);  
        temp=head;  
        for(i=0;i<loc;i++)  
        {  
            temp = temp->next;  
            if(temp == NULL)  
            {  
                printf("\ncan't insert\n");  
                return;  
            }  
          
        }  
        ptr ->next = temp ->next;   
        temp ->next = ptr;   
        printf("\nNode inserted");  
    }  
}  
void ll_insertlast()
{
    struct node*ptr,*p;
    p=(struct node *)malloc(sizeof(struct node));
      if(p == NULL)  
    {  
        printf("\nOVERFLOW");     
    }  
    else
    {
        printf("Enter Value:-");
        scanf("%d",&p->data);
          if(head == NULL)  
        {  
            p-> next = NULL;  
            head = p;  
            printf("\nNode inserted");  
        }  
        else
        {
            ptr=head;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=p;
            p->next=NULL;
            printf("\nNode Inserted");
        }
        
    }
    
}
void ll_delete_first()
{
    struct node*ptr;
    if(head==NULL)
    {
        printf("no node for deletion");
    }
    else
    {
    ptr=head;
    head=ptr->next;
    free(ptr);
    printf("Node Deleted Successfully");
    }
}
void ll_delete_atindex()
{
    struct node* p=head;;
    struct node* q=head->next;
     int index,i;    
    printf("\n Enter the location of the node after which you want to perform deletion \n");  
    scanf("%d",&index);  
    for ( i = 0; i < index-1; i++)
    {
        p=p->next;
        q=q->next;

        if(q==NULL)
        {
            printf("Can't Delete");
            return;
        }
    }
    p->next=q->next;
    free(q);
    printf("Node Deleted successfully");
    
}
void ll_delete_atend()
{
    struct node* p=head;
    struct node*q=head->next;
    if(head==NULL){
        printf("List is empty");
    }
    else if(head->next==NULL)
    {
        head=NULL;
        free(head);
        printf("No node left");

    }
    else{
        while(q->next!=NULL)
        {
            p=p->next;
            q=q->next;
        }
        p->next=NULL;
        free(q);
        printf("Node deleted Successfully");
    }
}