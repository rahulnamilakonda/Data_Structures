#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int info;
    int *prev;
};
struct node *top,*curr,*dis;
void push()
{
    printf("Enter the value to be pushed\n");
    if(top==NULL)
    {
    curr=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&curr->info);
    curr->prev=NULL;
    top=curr;
    }
    else
    {
    curr=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&curr->info);
    curr->prev=top;
    top=curr;
    }
    printf("Inserted Succesfully\n");
}
int pop()
{
    int val=-1;
    if(top==NULL)
    {
        
        return val;
    }
    else
    {
        val=top->info;
        top=top->prev;
        return val;
    }
}
void display()
{
    
    dis=top;
    if(dis==NULL)
    {
        printf("Stack is Underflow\n");
        return;
    }
    printf("The elements in stack are\n");
    while(dis!=NULL)
    {
        printf("%d->",dis->info);
        dis=dis->prev;
    }
}
int main()
{
    int ch;
    int val;
    top=NULL;
    do
    {
        system("cls");
        printf("Enter yor choice\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            push();
        }
        else if(ch==2)
        {
           val=pop();
           if(val!=-1)
           {
               printf("The elment poped is %d",val);
           }
           else
           {
               printf("Stack underflow\n");
           }
        }
        else if(ch==3)
        {
            display();
        }
        getch();
    } while (ch!=4);
    
}