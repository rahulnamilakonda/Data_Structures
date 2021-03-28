#include<stdio.h>
#include<conio.h>
struct stack
{
    int top;
    int x[5];
};
struct stack s={.top=-1};
int val;
void push()
{
    printf("Enter the element to pushed\n");
    scanf("%d",&val);
    if(s.top==4)
    {
        printf("Stack Overflow\n");
        return;
    }
    s.top++;
    s.x[s.top]=val;
}
int pop()
{
    if(s.top==-1)
    {
        return -1;
    }
    val=s.x[s.top];
    s.top--;
    return val;
}
void display()
{
    int i;
    printf("The elements in the stack are\n");
    for(i=0;i<=s.top;i++)
    {
    printf("%d->",s.x[i]);
    }
}
int main()
{
    int ch,re;
    
    do
    {
        system("cls");
        printf("Enter you choice\n");
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
            re=pop();
            if(re!=-1)
            {
                printf("The value poped is %d",re);
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