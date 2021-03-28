#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct snode
{
    int info;
    struct snode *next;
};
struct snode *head,*tail,*curr,*temp;
void append()
{
    curr=(struct snode*)malloc(sizeof(struct snode));
    curr->next=NULL;
    printf("Enter the element to append\n");
    scanf("%d",&curr->info);
    if(head==NULL)
    {
        head=tail=curr;
    }
    else
    {
     tail->next=curr;
     tail=curr;
    }
    
}
void traverse()
{
    if(head==NULL)
    {
        printf("NO Elements found\n");
        return;
    }
    else
    {
        curr=head;
        while(curr!=NULL)
        {
            printf("%d->",curr->info);
            curr=curr->next;
        }
    }
    
}
void insert()
{
    int val,index=0,i;
 if(head==NULL)
 {
    printf("List is Empty\n");
    return ;
 } 
 temp=(struct snode*)malloc(sizeof(struct snode));
 temp->next=NULL;
 printf("Enter the new Element to be inserted\n");
 scanf("%d",&temp->info);
 printf("Enter the postion to which the element needed to be inserted berfore\n");
 scanf("%d",&index);
 if(index==1)
 {
  temp->next=head;
  head=temp;
  printf("Inserted Successfully\n");
 }
 else
 {
  curr=head;
 for(i=0;i<index-2;i++)
 {
     curr=curr->next;
 }
 temp->next=curr->next;
 curr->next=temp;
 printf("Inserted Successfully\n");
 }
}
int remove()
{
    int val,index=0,i=0;
if(head==NULL)
{
    return -1;
}
else
{
    printf("Enter the element to be removed\n");
    scanf("%d",&val);
    if(head==tail && head->info==val)
    {
        return val;
        free(head);
        free(tail);
        head=tail=NULL;
    }
    else if(head!=tail && head->info==val)
    {
        temp=head;
        val=temp->info;
        head=head->next;
        free(temp);
        return val;
    
    }
    else if(head!=tail && tail->info==val)
    {
        curr=head;
        while(curr->next!=tail)
        curr=curr->next;
        curr->next=NULL;
        temp=tail;
        val=temp->info;
        tail=curr;
        free(temp);
        printf("removed Successfully\n");
        return val;
    }
    else
    {
        printf("enter the postion of element to be removed\n");
        scanf("%d",&index);
        curr=head;
        for(i=0;i<index-2;i++)
        {
            curr=curr->next;
        }
        temp=curr->next;
        val=curr->next->info;
        curr->next=curr->next->next;
        free(temp);
        return val;

    }

}
}
int main()
{
    int ch,val;
    head=tail=NULL;
    do
    {
        system("cls");
        printf("Enter your choice\n");
        printf("1.Append(creation)\n");
        printf("2.Traversal\n");
        printf("3.Insertion\n");
        printf("4.Remove(Deleltion)\n");
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
            insert();
        }
        else if(ch==4)
        {
            val=remove();
            if(val!=-1)
            {
                printf("%d Removed\n",val);
            }
            else
            {
                printf("List is Empty\n");
            }
        }
        getch();
    }while(ch!=5 && ch<=5);

    }