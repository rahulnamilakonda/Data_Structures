#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int x[11];
void inti()
{
    int i;
    for(i=0;i<11;i++)
    {
        x[i]=-1;
    }
}
void display()
{
    int i;
for(i=1;i<11;i++)
{
    printf("x[%d]=%d\n",i,x[i]);
}
}
void insert(int val)
{
int p;
p=1;
while(1)
{
    if(x[p]==-1)
    {
        x[p]=val;
        printf("inserted Successfully\n");
        break;
    }
    else if(val<x[p])
    {
        p=2*p;
        
    }
    else if(val>x[p])
    {
        p=2*p+1;
      
    }
    else if(val==x[p])
    {
        printf("Duplicates not Allowed\n");
    
        break;
    }
}
}
void search(int val)
{
int p;
p=1;
while(1)
{
    if(x[p]==-1)
    {
        printf("Element Not Found\n");
        break;
    }
    else if(val<x[p])
    {
        p=2*p;
    }
    else if(val>x[p])
    {
        p=2*p+1;
    }
    else if(val==x[p])
    {
        printf("Element %d found at %d",x[p],p);
        break;
    }
}
}
void preorder(int p)
{
    if(x[p]==-1)
    return;
    printf("%d\t",x[p]);
    preorder(2*p);
    preorder(2*p+1);
}
void inorder(int p)
{
    if(x[p]==-1)
    return;
    inorder(2*p);
    printf("%d\t",x[p]);
    inorder(2*p+1);
}
void postorder(int p)
{
    if(x[p]==-1)
    return;
    inorder(2*p);
    inorder(2*p+1);
    printf("%d\t",x[p]);
}
int main()
{
    int ch,val;
    inti();
    do
    {
        system("cls");
        printf("Enter your choice\n");
        printf("1.Insert\n");
        printf("2.Display\n");
        printf("3.Search\n");
        printf("4.preorder\n");
        printf("5.Inorder\n");
        printf("6.Post order\n");
        printf("7.exit\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("enter the Element to be inserted\n");
            scanf("%d",&val);
            insert(val);
        }
        else if(ch==2)
        {
            display();
        }
        else if(ch==3)
        {
            printf("enter the Element to be searched\n");
            scanf("%d",&val);
            search(val);
        }
        else if(ch==4)
        {
            preorder(1);
        }
        else if(ch==5)
        {
            inorder(1); 
        }
        else if(ch==6)
        {
            postorder(1);
        }
        getch();
    } while (ch!=7);
    

}