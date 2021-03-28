#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
    int info;
    struct node *lptr;
    struct node *rptr;
};
struct node *head,*tail,*curr,*temp;
void append()
{
    curr=(struct node *)malloc(sizeof(struct node));
    printf("Enter the Element to be append\n");
    scanf("%d",&curr->info);
    curr->lptr=NULL;
    curr->rptr=NULL;
    if(head==NULL)
    {
    head=tail=curr;
    }
    else
    {
     tail->rptr=curr;
     curr->lptr=tail;
     tail=curr;
     tail->rptr=NULL;

    }
    
}
void traverse()
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        curr=head;
        while(curr!=NULL)
        {
            printf("%d->",curr->info);
            curr=curr->rptr;
        }
    
    }
    
}
void retraverse()
{
    if(head==NULL)
    {
        printf("List is Empty\n");
        return;
    }
    else
    {
        curr=tail;
        while(curr!=NULL)
        {
            printf("%d->",curr->info);
            curr=curr->lptr;
        }
    }
    
}
void insert()
{
    int val;
    if(head==NULL)
    {
        printf("List is Empty\n");
        return;
    }
    else
    {
        printf("Enter the element to be inserted before\n");
        scanf("%d",&val);
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter the New element\n");
        scanf("%d",&temp->info);
        temp->rptr=NULL;
        temp->lptr=NULL;
        if(head->info==val)
        {
            head->lptr=temp;
            temp->rptr=head;
            head=temp;

        }
        else
        {
        curr=head;
        while(curr->info!=val && curr!=NULL)
        {
            curr=curr->rptr;
        }
        if(curr==NULL)
        printf("Element not found\n");
        else
        {
        temp->rptr=curr;
        temp->lptr=curr->lptr;
        curr->lptr=temp;
        temp->lptr->rptr=temp;
        }
        }

    }
    printf("Inserted Succesfully\n");
 }
 void nremove(int val)
 {
    if(head==NULL)
    {
        printf("list is empty\n");
        return ;
    }
    else if(head==tail && head->info==val)
    {
        free(head);
        free(tail);
        head=tail=NULL;
    }
    else if(head!=tail && head->info==val)
    {

        head=head->rptr;
        free(head->lptr);
        head->lptr=NULL;

    }
    else if(head!=tail && tail->info==val)
    {
        tail=tail->lptr;
        free(tail->rptr);
        tail->rptr=NULL;
    }
    else
    {
        curr=head;
        while(curr!=NULL && curr->info!=val)
        {
            curr=curr->rptr;
        }
        if(curr==NULL)
        {
            printf("List is empty");
        }
        else
        {
            curr->lptr->rptr=curr->rptr;
            curr->rptr->lptr=curr->lptr;
            free(curr);
        }
    }
    printf("Removed succesfully\n");
    
 }
int main()
{
    int ch,val;
    head=tail=NULL;
    do
    {
      system("cls");
      printf("Enter Your choice\n");
      printf("1.Append\n");
      printf("2.Traverse\n");
      printf("3.Retraverse\n");
      printf("4.Insertion\n");
      printf("5.Deleltion\n");
      printf("6.Exit\n");
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
          retraverse();
      }
      else if(ch==4)
      {
          insert();
      }
      else if(ch==5)
      {
          printf("Enter the element to be removed\n");
          scanf("%d",&val);
          nremove(val);
      }
      getch();

    } while(ch!=6);
    
}