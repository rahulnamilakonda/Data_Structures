#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct queue
{
    int front;
    int rear;
    int x[5];
};
struct queue q={.front=-1,.rear=-1};
void enqueue(int val)
{
    if(q.rear==4)
    {
        printf("Qeueue is full\n");
        return;
    }
    else
    {
        
        
        if(q.front==-1)
        {
            q.front=0;
        
        }
        q.rear++;
        q.x[q.rear]=val;
        printf("Inserted Successfully\n");
        

    }
}
int dequeue()
{
    int val;
    if(q.front==-1)
    {
        return -1;
    }
    val=q.x[q.front];
    if(q.front==q.rear)
    {
        q.front=q.rear=-1;
         
    }
    else
    {
    q.front++;
    }
    return val;
}
void display()
{
    int i;
    for(i=q.front;i<5;i++)
    {
        printf("%d->",q.x[i]);
    }
}
int main()
{
    int ch,val;
    do
    {
        system("cls");
        printf("Enter your choice\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("Enter the element to be enqueued\n");
            scanf("%d",&val);
            enqueue(val);
        }
        else if(ch==2)
        {
            val=dequeue();
            if(val!=-1)
            printf("The Element removed is %d\n",val);
            else
            printf("Queue is Empty\n");
        }
        else if(ch==3)
        {
            display();
        }
        getch();
    }while(ch!=4);

}