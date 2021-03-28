#include<stdio.h>
#include<conio.h>
struct queue
{
    int x[10];
    int front;
    int rear;
};
struct queue q={.front=-1,.rear=-1};
int nv;
int x[10][10];
int v[10];
void init()
{
    int i;
    for(i=0;i<10;i++)
    {
        v[i]=0;
    }
}
void enqueue(int val)
{
    if(q.rear==10)
    {
     printf("Queue is Full\n");
     return;
    }
    if(q.front==-1)
    {
        q.front=0;
    }
    q.rear++;
    q.x[q.rear]=val;
}
int dequeue()
{
    int val;
    if(q.front==10)
    {
        printf("Queue is Empty\n");
        return -1;
    }
    val=q.x[q.front];
    if(q.front==q.rear)
    {
        q.front=-1;
        q.rear=-1;
    }
    else
    q.front++;
    return val;

}
void bfs(int ve)
{
 int i=0;
 int p;
 if(ve>nv)
 {
     printf("Invalid Vertex\n");
     return ;
 }
 enqueue(ve);
 v[ve]=1;
 while(q.front!=-1)
 {
     p=dequeue();
     printf("%d",p);
     for(i=1;i<=nv;i++)
     {
        if(x[p][i]==1 && v[i]==0)
        {
            enqueue(i);
            v[i]=1;

        }
     }
 }
 printf("\n");
}
int main()
{
    
    
    int r,c,v,i,k;
    init();
    //
    system("cls");
    printf("Enter the number of vertices\n");
    scanf("%d",&nv);
    printf("Enter the adjacent matrix\n");
    for(r=1;r<=nv;r++)
    for(c=1;c<=nv;c++)
    scanf("%d",&x[r][c]);  
    printf("Starting vertex\n");
    scanf("%d",&v);
    for(i=1;i<=nv;i++)
    {
    bfs(i);
    for(k=0;k<10;k++)
    {
        init();
    }
    }
    getch();

}