#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *head,*tail,*curr,*temp;
void append()
{
    printf("Enter the Element to be inserted\n");
    curr=(struct node*)malloc(sizeof(struct node));
    curr->next=NULL;
    scanf("%d",&curr->info);
    if(head==NULL)
    {
        head=tail=curr;
    }
    else
    {
        tail->next=curr;
        tail=curr;
        tail->next=head;
    }
    printf("Inserted Successfully\n");
}
void traverse()
{
    curr=head;
    if(head==NULL)
    {
        printf("No Elements in Linkedlist\n");
        return;
    }
    printf("The Element in circular linkedlist are\n");
    while(curr->next!=head)
    {
        printf("%d->",curr->info);
        curr=curr->next;
    }
    printf("%d",curr->info);
}
int ndelete()
{
    int val,pos,i;
    if(head==NULL)
    {
        printf("No nodes in circular linked list");
        return;
    }
    printf("Enter The node to be Deleted\n");
    scanf("%d",&val);
    if(head->info==val && head==tail)
    {
        val=head->info;
        free(head);
        free(tail);
        head=tail=NULL;
        return val;
    }
    else if(head->info==val && head!=tail)
    {
        val=head->info;
        head=head->next;
        tail->next=head;
        return val;
    }
    else if(tail->info==val && head!=tail)
    {
        val=tail->info;
        curr=head;
        while(curr->next!=tail)
        curr=curr->next;
        temp=tail;
        tail=curr;
        tail->next=head;
        free(temp);
        return val;
        
    }
    else
    {
        printf("Enter The postion of Element to be removed\n");
        scanf("%d",&pos);
        curr=head;
        for(i=0;i<pos-2;i++)
        {
            curr=curr->next;

        }
        val=curr->next->info;
        temp=curr->next;
        curr->next=curr->next->next;
        free(temp);
        return val;
    }
}
void insert()
{
    int ch,val,val1,pos,i;
    if(head==NULL)
    {
        printf("NO nodes in circular linked_list\n");
        return ;
    }
    printf("Enter the Element to be inserted\n");
    curr=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&curr->info);
    curr->next=NULL;
    printf("Enter to Which element before to be inserted\n");
    scanf("%d",&val1);
    if(head->info==val1)
    {
        curr->next=head;
        head=curr;
        tail->next=head;
        printf("Inserted Successfully\n");
        
    }
    else
    {
        printf("Enter the Postion inserted Before\n");
        scanf("%d",&pos);
        temp=head;
        for(i=0;i<pos-2;i++)
        {
            temp=temp->next;
        }
        curr->next=temp->next;
        temp->next=curr;
        printf("Inserted successfully\n");
           

    }


}
int main()
{
    int ch,val;
    head=tail=NULL;
    do
    {
        system("cls");
        printf("Enter your Choice\n");
        printf("1.Append\n");
        printf("2.Traverse\n");
        printf("3.Delete\n");
        printf("4.Insert\n");
        printf("5.Exit\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            append();
        }
        else if(ch==2)
        {
            traverse();
        }
        else if(ch==3)
        {
            val=ndelete();
            if(val)
            {
                printf("Element removed is %d\n",val);
            }
        }
        else if(ch==4)
        {
            insert();
        }
        getch();
    } while (ch!=5);
    return 0;
}