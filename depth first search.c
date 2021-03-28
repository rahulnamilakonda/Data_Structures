#include<stdio.h>
#include<conio.h>
struct stack
{
    int x[10];
    int top;
};
struct stack s={.top=-1};
int x[10][10],v[10],nv;
void init()
{   
    int i; 
    for(i=0;i<10;i++)
    {
        v[i]=0;
    }
}
void push(int val)
{
    if(s.top==10)
    {
        printf("Stack is Overflow\n");
        return;
    }
    s.top++;
    s.x[s.top]=val;
    //printf("Inserted\n");
}
int pop()
{
    int val;
    if(s.top==-1)
    {
        printf("Stack is Underflow\n");
        return -1;
    }
    val=s.x[s.top];
    s.top--;
   // printf("Popped\n");
    return val;
}
int peek()
{
    int val;
    if(s.top==-1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
   // val=s.x[s.top];
    //printf("Peeked %d\n",val);
    return(s.x[s.top]);
}
void dfs(int ve)
{   
    int p,i,j;
    if(ve>nv)
    {
        printf("Invalid Vertex\n");
        return;
    }
    push(ve);
    v[ve]=1;
    printf("%d",ve);
    while(s.top!=-1)
    {
        p=peek();
        for(i=1;i<=nv;i++)
        {
            if(x[p][i]==1 && v[i]==0)
            {
                push(i);
                v[i]=1;
                printf("%d",i);
                break;
            }
        }
        if(i>nv)
            {
                pop();
            }
    }
    printf("\n");    
}
int main()
{
    int i,r,c,j;
    system("cls");
    init();
    printf("Enter the number of vertices\n");
    scanf("%d",&nv);
    for(r=1;r<=nv;r++)
    {
        for(c=1;c<=nv;c++)
        {
            scanf("%d",&x[r][c]);
        }
    }
    printf("All Possible Combinations are\n");
   for(i=1;i<=nv;i++)
    {
        dfs(i);
        for(j=0;j<10;j++)
        {
            init();
        }
    }

}